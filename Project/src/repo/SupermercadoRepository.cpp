#include "../../include/repo/SupermercadoRepository.h"
#include <fstream>
#include <sstream>

SupermercadoRepository* SupermercadoRepository::instance = NULL;

SupermercadoRepository::SupermercadoRepository() {
    carregarProdutos();
    carregarCategorias();
}

SupermercadoRepository& SupermercadoRepository::getInstance() {
    if (instance == NULL) {
        instance = new SupermercadoRepository();
    }
    return *instance;
}

// ==================== PRODUTOS ====================

std::vector<Produto>& SupermercadoRepository::getProdutos() {
    return produtos;
}

void SupermercadoRepository::guardarProdutos() {
    std::ofstream ficheiro("../produtos.csv");
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

        Produto p(id, nome, preco_base, stock, id_categoria);
        produtos.push_back(p);
    }
    ficheiro.close();
}

// ==================== CATEGORIAS ====================

std::vector<Categoria>& SupermercadoRepository::getCategorias() {
    return categorias;
}

void SupermercadoRepository::guardarCategorias() {
    std::ofstream ficheiro("../categorias.csv");
    if (!ficheiro.is_open()) return;

    for (int i = 0; i < (int)categorias.size(); i++) {
        ficheiro << categorias[i].getId() << "," << categorias[i].getNome() << "," << categorias[i].getTaxaIva() << "\n";
    }
    ficheiro.close();
}

void SupermercadoRepository::carregarCategorias() {
    std::ifstream ficheiro("../categorias.csv");
    if (!ficheiro.is_open()) return;

    std::string linha;
    while (std::getline(ficheiro, linha)) {
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

        Categoria c(id, nome, taxa_iva);
        categorias.push_back(c);
    }
    ficheiro.close();
}
