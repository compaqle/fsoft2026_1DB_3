#include "../../include/controller/CategoriaController.h"
#include <fstream>
#include <sstream>

CategoriaController::CategoriaController() {
    caminhoFicheiro = "../categorias.csv";
    proximoId = 1;
    carregarFicheiro();
}

void CategoriaController::criarCategoria(std::string nome, double taxa_iva) {
    Categoria c(proximoId, nome, taxa_iva);
    categorias.push_back(c);
    proximoId++;
    guardarEmFicheiro();
}

std::vector<Categoria>& CategoriaController::getCategorias() {
    return categorias;
}

void CategoriaController::guardarEmFicheiro() {
    std::ofstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) return;

    for (int i = 0; i < (int)categorias.size(); i++) {
        ficheiro << categorias[i].getId() << "," << categorias[i].getNome() << "," << categorias[i].getTaxaIva() << "\n";
    }
    ficheiro.close();
}

void CategoriaController::carregarFicheiro() {
    std::ifstream ficheiro(caminhoFicheiro);

    if (!ficheiro.is_open()) {
        return;
    }

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

        if (id >= proximoId) {
            proximoId = id + 1;
        }
    }

    ficheiro.close();
}