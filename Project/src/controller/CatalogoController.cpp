#include "../../include/controller/CatalogoController.h"
#include <fstream>
#include <sstream>

CatalogoController::CatalogoController() {
    caminhoFicheiro = "../produtos.csv";
    proximoId = 1;
    carregarFicheiro();
}

void CatalogoController::criarProduto(std::string nome, double preco_base, int stock, int id_categoria) {
    Produto p(proximoId, nome, preco_base, stock, id_categoria);
    produtos.push_back(p);
    proximoId++;
    guardarEmFicheiro();
}

void CatalogoController::removerProduto(int id) {
    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].getId() == id) {
            produtos.erase(produtos.begin() + i);
            guardarEmFicheiro();
            return;
        }
    }
}

std::vector<Produto>& CatalogoController::getProdutos() {
    return produtos;
}

void CatalogoController::guardarEmFicheiro() {
    std::ofstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) return;

    for (int i = 0; i < (int)produtos.size(); i++) {
        ficheiro << produtos[i].getId() << ","
                 << produtos[i].getNome() << ","
                 << produtos[i].getPrecoBase() << ","
                 << produtos[i].getStock() << ","
                 << produtos[i].getIdCategoria() << "\n";
    }
    ficheiro.close();
}

void CatalogoController::carregarFicheiro() {
    std::ifstream ficheiro(caminhoFicheiro);

    if (!ficheiro.is_open()) {
        return;
    }

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

        Produto p(id, nome, preco_base, stock, id_categoria);
        produtos.push_back(p);

        if (id >= proximoId) {
            proximoId = id + 1;
        }
    }

    ficheiro.close();
}
