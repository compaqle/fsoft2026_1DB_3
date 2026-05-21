#include "../../include/repo/SupermercadoRepository.h"
#include <fstream>
#include <sstream>

SupermercadoRepository* SupermercadoRepository::instance = NULL;

SupermercadoRepository::SupermercadoRepository() {
    carregarCategorias();
    carregarProdutos();
}

SupermercadoRepository::~SupermercadoRepository() {
    for (size_t i = 0; i < produtos.size(); i++) {
        delete produtos[i];
    }
    for (size_t i = 0; i < categorias.size(); i++) {
        delete categorias[i];
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
