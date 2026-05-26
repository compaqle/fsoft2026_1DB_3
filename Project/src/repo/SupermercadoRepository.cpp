#include "../../include/repo/SupermercadoRepository.h"
#include "../../include/model/ItemVenda.h"
#include <fstream>
#include <sstream>

SupermercadoRepository* SupermercadoRepository::instance = NULL;

SupermercadoRepository::SupermercadoRepository() {
    carregarCategorias();
    carregarProdutos();
    carregarClientes();
    carregarCaixas();
    carregarPromocoes();
    carregarVendas();
}

SupermercadoRepository::~SupermercadoRepository() {
    for (size_t i = 0; i < produtos.size(); i++) {
        delete produtos[i];
    }
    for (size_t i = 0; i < categorias.size(); i++) {
        delete categorias[i];
    }
    for (size_t i = 0; i < clientes.size(); i++) {
        delete clientes[i];
    }
    for (size_t i = 0; i < caixas.size(); i++) {
        delete caixas[i];
    }
    for (size_t i = 0; i < vendas.size(); i++) {
        delete vendas[i];
    }
    for (size_t i = 0; i < promocoes.size(); i++) {
        delete promocoes[i];
    }
}

SupermercadoRepository& SupermercadoRepository::getInstance() {
    if (instance == NULL) {
        instance = new SupermercadoRepository();
    }
    return *instance;
}

// ==================== PRODUTOS ====================

std::vector<Produto*>& SupermercadoRepository::getProdutos() {
    return produtos;
}

void SupermercadoRepository::guardarProdutos() {
    std::ofstream ficheiro("../produtos.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < produtos.size(); i++) {
        ficheiro << produtos[i]->getId() << ","
                 << produtos[i]->getNome() << ","
                 << produtos[i]->getPrecoBase() << ","
                 << produtos[i]->getStock() << ","
                 << (produtos[i]->getCategoria() ? produtos[i]->getCategoria()->getId() : 0) << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarProdutos() {
    std::ifstream ficheiro("../produtos.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        int id, stock, id_categoria;
        std::string nome;
        double preco_base;

        std::getline(ss, campo, ',');
        id = std::stoi(campo);

        std::getline(ss, nome, ',');

        std::getline(ss, campo, ',');
        preco_base = std::stod(campo);

        std::getline(ss, campo, ',');
        stock = std::stoi(campo);

        std::getline(ss, campo, ',');
        id_categoria = std::stoi(campo);

        Categoria* categoriaPointer = NULL;
        for (size_t i = 0; i < categorias.size(); i++) {
            if (categorias[i]->getId() == id_categoria) {
                categoriaPointer = categorias[i];
                break;
            }
        }

        Produto* p = new Produto(id, nome, preco_base, stock, categoriaPointer);
        produtos.push_back(p);
    }
    ficheiro.close();
}

// ==================== CATEGORIAS ====================

std::vector<Categoria*>& SupermercadoRepository::getCategorias() {
    return categorias;
}

void SupermercadoRepository::guardarCategorias() {
    std::ofstream ficheiro("../categorias.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < categorias.size(); i++) {
        ficheiro << categorias[i]->getId() << "," << categorias[i]->getNome() << "," << categorias[i]->getTaxaIva() << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarCategorias() {
    std::ifstream ficheiro("../categorias.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string campo;
        int id;
        std::string nome;
        double taxa_iva;

        std::getline(ss, campo, ',');
        id = std::stoi(campo);

        std::getline(ss, nome, ',');

        std::getline(ss, campo, ',');
        taxa_iva = std::stod(campo);

        Categoria* c = new Categoria(id, nome, taxa_iva);
        categorias.push_back(c);
    }
    ficheiro.close();
}

// ==================== CLIENTES ====================

std::vector<Cliente*>& SupermercadoRepository::getClientes() {
    return clientes;
}

void SupermercadoRepository::guardarClientes() {
    std::ofstream ficheiro("../clientes.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < clientes.size(); i++) {
        ficheiro << clientes[i]->getNif() << ","
                 << clientes[i]->getNome() << ","
                 << clientes[i]->getSaldoPontos() << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarClientes() {
    std::ifstream ficheiro("../clientes.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string campo;
        int nif, pontos;
        std::string nome;

        std::getline(ss, campo, ','); nif = std::stoi(campo);
        std::getline(ss, nome, ',');
        std::getline(ss, campo, ','); pontos = std::stoi(campo);

        Cliente* c = new Cliente(nif, nome, pontos);
        clientes.push_back(c);
    }
    ficheiro.close();
}

// ==================== CAIXAS ====================

std::vector<Caixa*>& SupermercadoRepository::getCaixas() {
    return caixas;
}

void SupermercadoRepository::guardarCaixas() {
    std::ofstream ficheiro("../caixas.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < caixas.size(); i++) {
        ficheiro << caixas[i]->getId() << ","
                 << caixas[i]->getNome() << ","
                 << caixas[i]->getTotalFaturado() << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarCaixas() {
    std::ifstream ficheiro("../caixas.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string campo;
        int id;
        std::string nome;
        double total_faturado;

        std::getline(ss, campo, ','); id = std::stoi(campo);
        std::getline(ss, nome, ',');
        std::getline(ss, campo, ','); total_faturado = std::stod(campo);

        Caixa* c = new Caixa(id, nome);
        c->adicionarFaturacao(total_faturado);
        caixas.push_back(c);
    }
    ficheiro.close();
}

// ==================== PROMOCOES ====================

std::vector<Promocao*>& SupermercadoRepository::getPromocoes() {
    return promocoes;
}

void SupermercadoRepository::guardarPromocoes() {
    std::ofstream ficheiro("../promocoes.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < promocoes.size(); i++) {
        // guarda id_produto (0 se NULL) e id_categoria (0 se NULL)
        int id_produto = promocoes[i]->getProduto() ? promocoes[i]->getProduto()->getId() : 0;
        int id_categoria = promocoes[i]->getCategoria() ? promocoes[i]->getCategoria()->getId() : 0;

        ficheiro << promocoes[i]->getId() << ","
                 << promocoes[i]->getPercentagem() << ","
                 << promocoes[i]->getData_Inicio() << ","
                 << promocoes[i]->getData_Final() << ","
                 << id_produto << ","
                 << id_categoria << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarPromocoes() {
    std::ifstream ficheiro("../promocoes.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string campo;
        int id, id_produto, id_categoria;
        double percentagem;
        std::string data_inicio, data_final;

        std::getline(ss, campo, ','); id = std::stoi(campo);
        std::getline(ss, campo, ','); percentagem = std::stod(campo);
        std::getline(ss, data_inicio, ',');
        std::getline(ss, data_final, ',');
        std::getline(ss, campo, ','); id_produto = std::stoi(campo);
        std::getline(ss, campo, ','); id_categoria = std::stoi(campo);

        // resolve ponteiros
        Produto* produtoPointer = NULL;
        for (size_t i = 0; i < produtos.size(); i++) {
            if (produtos[i]->getId() == id_produto) {
                produtoPointer = produtos[i];
                break;
            }
        }

        Categoria* categoriaPointer = NULL;
        for (size_t i = 0; i < categorias.size(); i++) {
            if (categorias[i]->getId() == id_categoria) {
                categoriaPointer = categorias[i];
                break;
            }
        }

        Promocao* p = new Promocao(id, percentagem, data_inicio, data_final, produtoPointer, categoriaPointer);
        promocoes.push_back(p);
    }
    ficheiro.close();
}

// ==================== VENDAS ====================

std::vector<Venda*>& SupermercadoRepository::getVendas() {
    return vendas;
}

void SupermercadoRepository::guardarVendas() {
    std::ofstream ficheiro("../vendas.csv");
    if (!ficheiro.is_open()) return;

    for (size_t i = 0; i < vendas.size(); i++) {
        // linha da venda: id, nif_cliente (0 se sem cliente), data_hora, total, metodo_pagamento
        int nif_cliente = vendas[i]->getCliente() ? vendas[i]->getCliente()->getNif() : 0;

        ficheiro << vendas[i]->getId() << ","
                 << nif_cliente << ","
                 << vendas[i]->getDataHora() << ","
                 << vendas[i]->getTotal() << ","
                 << vendas[i]->getMetodoPagamento() << "\n";

        // linha por cada item: ITEM, id_venda, id_produto, quantidade, preco_unitario, subtotal
        std::vector<ItemVenda> itens = vendas[i]->getVendas();
        for (size_t j = 0; j < itens.size(); j++) {
            ficheiro << "ITEM,"
                     << vendas[i]->getId() << ","
                     << itens[j].getProduto()->getId() << ","
                     << itens[j].getQuantidade() << ","
                     << itens[j].getPrecoUnitario() << ","
                     << itens[j].getSubtotal() << "\n";
        }
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarVendas() {
    std::ifstream ficheiro("../vendas.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    Venda* vendaAtual = NULL;

    while (std::getline(ficheiro, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string campo;

        std::getline(ss, campo, ',');

        if (campo == "ITEM") {
            // linha de item — adiciona à venda atual
            if (vendaAtual == NULL) continue;

            std::string id_venda_str, id_produto_str, quantidade_str, preco_str, subtotal_str;
            std::getline(ss, id_venda_str, ',');
            std::getline(ss, id_produto_str, ',');
            std::getline(ss, quantidade_str, ',');
            std::getline(ss, preco_str, ',');
            std::getline(ss, subtotal_str, ',');

            int id_produto = std::stoi(id_produto_str);
            int quantidade = std::stoi(quantidade_str);
            double preco_unitario = std::stod(preco_str);
            double subtotal = std::stod(subtotal_str);

            Produto* produtoPointer = NULL;
            for (size_t i = 0; i < produtos.size(); i++) {
                if (produtos[i]->getId() == id_produto) {
                    produtoPointer = produtos[i];
                    break;
                }
            }

            if (produtoPointer != NULL) {
                vendaAtual->adicionarItem(ItemVenda(produtoPointer, quantidade, preco_unitario, subtotal));
            }

        } else {
            // linha de venda
            int id = std::stoi(campo);
            std::string nif_str, data_hora, total_str, metodo;

            std::getline(ss, nif_str, ',');
            std::getline(ss, data_hora, ',');
            std::getline(ss, total_str, ',');
            std::getline(ss, metodo, ',');

            int nif = std::stoi(nif_str);
            double total = std::stod(total_str);

            // resolve ponteiro do cliente
            Cliente* clientePointer = NULL;
            if (nif != 0) {
                for (size_t i = 0; i < clientes.size(); i++) {
                    if (clientes[i]->getNif() == nif) {
                        clientePointer = clientes[i];
                        break;
                    }
                }
            }

            vendaAtual = new Venda(id, clientePointer);
            vendaAtual->setDataHora(data_hora);
            vendaAtual->setTotal(total);
            vendaAtual->setMetodoPagamento(metodo);
            vendas.push_back(vendaAtual);
        }
    }
    ficheiro.close();
}
