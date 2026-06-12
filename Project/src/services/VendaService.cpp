#include "../../include/services/VendaService.h"
#include "../../include/mappers/VendaMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/model/Venda.h"
#include "../../include/model/Produto.h"
#include "../../include/model/Cliente.h"
#include "../../include/model/Caixa.h"
#include "../../include/model/Promocao.h"
#include "../../include/model/Categoria.h"
#include "../../include/model/ItemVenda.h"
#include <ctime>
#include <sstream>
#include <iomanip>

VendaService::VendaService() {
    proximoId = 1;
    idVendaAtiva = -1;
    vendaEmCurso = false;

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() >= proximoId) {
            proximoId = vendas[i]->getId() + 1;
        }
    }
}

// anda a procura da melhor promocao ativa para este produto, ve as promocoes de produto e de categoria e fica com a maior
double VendaService::calcularMelhorDesconto(int id_produto) const {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Promocao*>& promocoes = repo.getPromocoes();
    std::vector<Produto*>& produtos = repo.getProdutos();

    Produto* produto = NULL;
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id_produto) {
            produto = produtos[i];
            break;
        }
    }
    if (produto == NULL) return 0.0;

    // sacar a data de hoje para ver se a promocao ainda esta ativa
    std::time_t t = std::time(NULL);
    std::tm* tm_info = std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(tm_info, "%Y-%m-%d");
    std::string hoje = oss.str();

    double melhorDesconto = 0.0;

    for (size_t i = 0; i < promocoes.size(); i++) {
        Promocao* p = promocoes[i];
        // se a promocao ja expirou ou ainda nao comecou, salta
        if (hoje < p->getData_Inicio() || hoje > p->getData_Final()) {
            continue;
        }
        // ve se a promocao e para este produto ou para a categoria dele
        bool aplicavel = false;
        if (p->getProduto() != NULL && p->getProduto()->getId() == id_produto) {
            aplicavel = true;
        }
        if (p->getCategoria() != NULL && produto->getCategoria() != NULL
            && p->getCategoria()->getId() == produto->getCategoria()->getId()) {
            aplicavel = true;
        }
        if (aplicavel && p->getPercentagem() > melhorDesconto) {
            melhorDesconto = p->getPercentagem(); // fica so com a maior, se houver varias
        }
    }
    return melhorDesconto;
}

double VendaService::consultarPreco(int id_produto) const {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto*>& produtos = repo.getProdutos();
    Produto* produto = NULL;
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id_produto) {
            produto = produtos[i];
            break;
        }
    }
    if (produto == NULL) {
        throw NoDataException("Produto: id = " + std::to_string(id_produto) + " (nao encontrado)");
    }
    double desconto = calcularMelhorDesconto(id_produto);
    // primeiro tira o desconto e so depois mete o IVA por cima, senao o desconto ia incidir sobre o IVA tambem
    double preco = produto->getPrecoBase() * (1.0 - desconto / 100.0);
    if (produto->getCategoria() != NULL) {
        preco = preco * (1.0 + produto->getCategoria()->getTaxaIva() / 100.0);
    }
    return preco;
}

void VendaService::iniciarVenda(int nif_cliente) {
    if (vendaEmCurso) {
        throw InvalidDataException("Ja existe uma venda em curso.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Cliente* cliente = NULL;
    if (nif_cliente != 0) {
        std::vector<Cliente*>& clientes = repo.getClientes();
        for (size_t i = 0; i < clientes.size(); i++) {
            if (clientes[i]->getNif() == nif_cliente) {
                cliente = clientes[i];
                break;
            }
        }
        if (cliente == NULL) {
            throw NoDataException("Cliente: nif = " + std::to_string(nif_cliente) + " (nao encontrado)");
        }
    }

    Venda* novaVenda = new Venda(proximoId, cliente);
    repo.getVendas().push_back(novaVenda);
    idVendaAtiva = proximoId;
    proximoId++;
    vendaEmCurso = true;
}

void VendaService::adicionarItem(int id_produto, int quantidade) {
    if (!vendaEmCurso) {
        throw InvalidDataException("Nao ha venda em curso.");
    }
    if (quantidade <= 0) {
        throw InvalidDataException("Quantidade invalida: " + std::to_string(quantidade));
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Produto* produto = NULL;
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id_produto) {
            produto = produtos[i];
            break;
        }
    }
    if (produto == NULL) {
        throw NoDataException("Produto: id = " + std::to_string(id_produto) + " (nao encontrado)");
    }
    if (produto->getStock() < quantidade) { // RF07
        throw InvalidDataException("Stock insuficiente. Disponivel: " + std::to_string(produto->getStock()));
    }

    // calcular o preco com desconto e iva (igual ao consultarPreco)
    double desconto = calcularMelhorDesconto(id_produto);
    double preco_unitario = produto->getPrecoBase() * (1.0 - desconto / 100.0);
    if (produto->getCategoria() != NULL) {
        preco_unitario = preco_unitario * (1.0 + produto->getCategoria()->getTaxaIva() / 100.0);
    }
    double subtotal = preco_unitario * quantidade;

    // procurar a venda ativa para lhe espetar o item
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() == idVendaAtiva) {
            vendas[i]->adicionarItem(ItemVenda(produto, quantidade, preco_unitario, subtotal));
            vendas[i]->setTotal(vendas[i]->getTotal() + subtotal);
            break;
        }
    }
}

void VendaService::removerItem(int id_produto) {
    if (!vendaEmCurso) {
        throw InvalidDataException("Nao ha venda em curso.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() != idVendaAtiva) continue;

        std::vector<ItemVenda> itens = vendas[i]->getVendas();
        // nao ha removeItem na classe Venda, entao a solucao e recriar a venda toda de novo sem o item que queremos tirar. e feio mas funciona
        bool encontrado = false;
        double novoTotal = 0.0;
        Venda* vendaTemp = new Venda(vendas[i]->getId(), vendas[i]->getCliente());
        vendaTemp->setDataHora(vendas[i]->getDataHora());
        vendaTemp->setMetodoPagamento(vendas[i]->getMetodoPagamento());

        for (size_t j = 0; j < itens.size(); j++) {
            if (itens[j].getProduto()->getId() == id_produto && !encontrado) {
                encontrado = true; // so tira a primeira ocorrencia, se houver duplicates
                continue;
            }
            vendaTemp->adicionarItem(itens[j]);
            novoTotal += itens[j].getSubtotal();
        }
        if (!encontrado) {
            delete vendaTemp;
            throw NoDataException("Produto nao encontrado na venda.");
        }
        vendaTemp->setTotal(novoTotal);
        delete vendas[i];
        vendas[i] = vendaTemp;
        return;
    }
}

double VendaService::calcularTotal() const {
    if (!vendaEmCurso) return 0.0;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() == idVendaAtiva) {
            return vendas[i]->getTotal();
        }
    }
    return 0.0;
}

VendaDTO VendaService::concluirVenda(const std::string& metodo_pagamento, int id_caixa) {
    if (!vendaEmCurso) {
        throw InvalidDataException("Nao ha venda em curso.");
    }
    if (metodo_pagamento.empty()) {
        throw InvalidDataException("Metodo de pagamento invalido.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    Venda* venda = NULL;
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() == idVendaAtiva) {
            venda = vendas[i];
            break;
        }
    }
    if (venda == NULL) {
        throw NoDataException("Venda ativa nao encontrada.");
    }

    // mete a data e hora em que a venda foi finalizada
    std::time_t t = std::time(NULL);
    std::tm* tm_info = std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(tm_info, "%Y-%m-%d %H:%M:%S");
    venda->setDataHora(oss.str());
    venda->setMetodoPagamento(metodo_pagamento);

    // tirar os produtos do stock
    std::vector<ItemVenda> itens = venda->getVendas();
    for (size_t i = 0; i < itens.size(); i++) {
        itens[i].getProduto()->removerStock(itens[i].getQuantidade());
    }
    repo.guardarProdutos();

    // aumentar o total faturado pelo caixa que fez a venda
    std::vector<Caixa*>& caixas = repo.getCaixas();
    for (size_t i = 0; i < caixas.size(); i++) {
        if (caixas[i]->getId() == id_caixa) {
            caixas[i]->adicionarFaturacao(venda->getTotal());
            break;
        }
    }
    repo.guardarCaixas();

    // dar pontos ao cliente, 1 ponto por cada 10 euros gastos
    if (venda->getCliente() != NULL) {
        venda->getCliente()->ganharPontos(static_cast<int>(venda->getTotal()));
        repo.guardarClientes();
    }

    repo.guardarVendas();

    vendaEmCurso = false;
    idVendaAtiva = -1;
    return VendaMapper::toDTO(*venda);
}

void VendaService::cancelarVenda() {
    if (!vendaEmCurso) return;

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < (int)vendas.size(); i++) {
        if (vendas[i]->getId() == idVendaAtiva) {
            delete vendas[i];
            vendas.erase(vendas.begin() + i);
            break;
        }
    }
    vendaEmCurso = false;
    idVendaAtiva = -1;
    proximoId--; // como a venda foi cancelada, libertamos o id que tava reservado
}

bool VendaService::temVendaAtiva() const {
    return vendaEmCurso;
}

VendaDTO VendaService::getVendaAtiva() const {
    if (!vendaEmCurso) {
        throw InvalidDataException("Nao ha venda em curso.");
    }
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() == idVendaAtiva) {
            return VendaMapper::toDTO(*vendas[i]);
        }
    }
    throw NoDataException("Venda ativa nao encontrada.");
}

std::vector<VendaDTO> VendaService::getVendas() const {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    std::vector<VendaDTO> dtos;
    for (size_t i = 0; i < vendas.size(); i++) {
        // a venda que esta a decorrer agora nao conta, so as finalizadas
        if (vendaEmCurso && vendas[i]->getId() == idVendaAtiva) continue;
        dtos.push_back(VendaMapper::toDTO(*vendas[i]));
    }
    return dtos;
}

std::vector<VendaDTO> VendaService::getVendasDoCaixa(int id_caixa) const {
    // nao temos ligacao entre venda e caixa, por isso devolvemos todas as vendas concluidas e o controller que filtre
    return getVendas();
}

VendaDTO VendaService::getVendaPorId(int id) const {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Venda*>& vendas = repo.getVendas();
    for (size_t i = 0; i < vendas.size(); i++) {
        if (vendas[i]->getId() == id) {
            return VendaMapper::toDTO(*vendas[i]);
        }
    }
    throw NoDataException("Venda: id = " + std::to_string(id) + " (nao encontrada)");
}
