#include "../../include/services/VendaService.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/model/Produto.h"
#include "../../include/model/Categoria.h"
#include "../../include/model/Venda.h"
#include "../../include/model/ItemVenda.h"
#include "../../include/model/Caixa.h"
#include "../../include/repo/SupermercadoRepository.h"
#include <ctime>

VendaService::VendaService(SupermercadoRepository& repo) : repo(repo) {}

Venda* VendaService::abrirVenda(Caixa* caixa, Cliente* cliente) {
    int novoId = (int)repo.getVendas().size() + 1;
    Venda* novaVenda = new Venda(novoId, cliente);

    time_t agora = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&agora));
    novaVenda->setDataHora(std::string(buffer));

    if (caixa != nullptr) {
        caixa->setVendaAtual(novaVenda);
    }
    return novaVenda;
}


void VendaService::adicionarItem(Venda* venda, int idProduto, int quantidade) {
    Produto* produtoEncontrado = nullptr;
    std::vector<Produto*>& produtos = repo.getProdutos();

    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i] != nullptr && produtos[i]->getId() == idProduto) {
            produtoEncontrado = produtos[i];
            break;
        }
    }

    if (produtoEncontrado == nullptr) {
        throw NoDataException("Produto com id " + std::to_string(idProduto) + " nao encontrado.");
    }

    verificarStock(produtoEncontrado, quantidade);

    double precoComIva = calcularPrecoComIva(produtoEncontrado);
    double subtotal = precoComIva * quantidade;

    ItemVenda item(produtoEncontrado, quantidade, precoComIva, subtotal);
    if (venda != nullptr) {
        venda->adicionarItem(item);
    }


    produtoEncontrado->removerStock(quantidade);
}


void VendaService::fecharVenda(Venda* venda, Caixa* caixa, const std::string& metodoPagamento) {
    if (venda == nullptr) return;

    double total = 0.0;

    std::vector<ItemVenda> itens = venda->getVendas();

    for (int i = 0; i < (int)itens.size(); i++) {
        total += itens[i].getSubtotal();
    }

    venda->setTotal(total);
    venda->setMetodoPagamento(metodoPagamento);

    if (caixa != nullptr) {
        caixa->adicionarFaturacao(total);
        caixa->fecharVendaAtual(venda);
    }

    repo.getVendas().push_back(*venda);
    repo.guardarVendas();
    repo.guardarProdutos();

    delete venda;
}


double VendaService::consultarPreco(int idProduto) const {
    std::vector<Produto*>& produtos = repo.getProdutos();

    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i] != nullptr && produtos[i]->getId() == idProduto) {
            return calcularPrecoComIva(produtos[i]);
        }
    }
    throw NoDataException("Produto nao encontrado.");
}



Venda* VendaService::getUltimaVenda() const {
    std::vector<Venda*>& vendas = repo.getVendas();
    if (vendas.empty()) {
        throw NoDataException("Nao existem vendas registadas.");
    }
    return vendas.back();
}

const std::vector<Venda*>& VendaService::getVendas() const {
double VendaService::calcularPrecoComIva(Produto* produto) const {
    if (produto == nullptr) return 0.0;

    std::vector<Categoria*>& categorias = repo.getCategorias();

    for (int i = 0; i < (int)categorias.size(); i++) {
        if (categorias[i] != nullptr && categorias[i]->getId() == produto->getCategoria()->getId()) {
            double taxa = categorias[i]->getTaxaIva();
            return produto->getPrecoBase() * (1.0 + taxa / 100.0);
        }
    }
    return produto->getPrecoBase();
}


void VendaService::verificarStock(Produto* produto, int quantidade) const {
    if (produto == nullptr) return;

    if (produto->getStock() < quantidade) {
        throw InvalidDataException(
            "Stock insuficiente para o produto " + produto->getNome() +
            ". Stock disponivel: " + std::to_string(produto->getStock())
        );
    }
}