#include "../../include/view/CategoriaView.h"
#include "../../include/view/Utils.h"
#include <iostream>

CategoriaView::CategoriaView() {}

int CategoriaView::mostrarMenuCategorias() {
    std::cout << "\n--- GERIR CATEGORIAS ---" << std::endl;
    std::cout << "1. Criar Categoria" << std::endl;
    std::cout << "2. Listar Categorias" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

void CategoriaView::getDadosCriarCategoria(std::string& nome, double& taxa_iva) {
    nome = Utils::lerString("Nome da Categoria: ");
    taxa_iva = Utils::lerDouble("Taxa de IVA (ex: 0.23 para 23%): ");
}

void CategoriaView::printListaCategorias(std::vector<Categoria>& lista) {
    if (lista.empty()) {
        std::cout << "\nNao existem categorias registadas." << std::endl;
        return;
    }
    std::cout << "\n--- LISTA DE CATEGORIAS ---" << std::endl;
    for (int i = 0; i < (int)lista.size(); i++) {
        std::cout << "ID: " << lista[i].getId()
                  << " | Nome: " << lista[i].getNome()
                  << " | IVA: " << (lista[i].getTaxaIva() * 100) << "%" << std::endl;
    }
}

void CategoriaView::printMensagem(const std::string& msg) {
    std::cout << msg << std::endl;
}
