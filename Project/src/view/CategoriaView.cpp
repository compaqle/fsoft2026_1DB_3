#include "../../include/view/CategoriaView.h"
#include "../../include/view/Utils.h"
#include <iostream>

CategoriaView::CategoriaView() {}

int CategoriaView::mostrarMenuCategorias() {
    std::cout << "\n--- GERIR CATEGORIAS ---" << std::endl;
    std::cout << "1. Criar Categoria" << std::endl;
    std::cout << "2. Listar Categorias" << std::endl;
    std::cout << "3. Editar Categoria" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

void CategoriaView::getDadosCriarCategoria(std::string& nome, double& taxa_iva) {
    nome = Utils::lerString("Nome da Categoria: ");
    taxa_iva = Utils::lerDouble("Taxa de IVA (ex: 23 para 23%): ");
}

int CategoriaView::getIdCategoriaEditar() {
    return Utils::lerInt("ID da categoria a editar: ");
}

void CategoriaView::printListaCategorias(const std::vector<CategoriaDTO>& lista) {
    std::cout << "\n--- LISTA DE CATEGORIAS ---" << std::endl;
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << "ID: " << lista[i].id
                  << " | Nome: " << lista[i].nome
                  << " | IVA: " << (lista[i].taxa_iva * 100) << "%" << std::endl;
    }
}
