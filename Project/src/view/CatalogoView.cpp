#include "../../include/view/CatalogoView.h"
#include "../../include/view/Utils.h"
#include <iostream>

CatalogoView::CatalogoView() {}

int CatalogoView::mostrarMenuCatalogo() {
    std::cout << "\n--- GERIR CATALOGO ---" << std::endl;
    std::cout << "1. Criar Produto" << std::endl;
    std::cout << "2. Listar Produtos" << std::endl;
    std::cout << "3. Editar Produto" << std::endl;
    std::cout << "4. Remover Produto" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

void CatalogoView::getDadosCriarProduto(std::string& nome, double& preco, int& stock, int& id_categoria) {
    nome = Utils::lerString("Nome: ");
    preco = Utils::lerDouble("Preco base: ");
    stock = Utils::lerInt("Stock: ");
    id_categoria = Utils::lerInt("ID Categoria: ");
}

int CatalogoView::getIdProduto() {
    return Utils::lerInt("ID do produto a remover: ");
}

int CatalogoView::getIdProdutoEditar() {
    return Utils::lerInt("ID do produto a editar: ");
}

void CatalogoView::printListaProdutos(const std::vector<ProdutoDTO>& lista) {
    if (lista.empty()) {
        std::cout << "\nO catalogo esta vazio." << std::endl;
        return;
    }
    std::cout << "\n--- LISTA DE PRODUTOS ---" << std::endl;
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << "ID: " << lista[i].id
                  << " | Nome: " << lista[i].nome
                  << " | Preco: " << lista[i].preco
                  << " | Stock: " << lista[i].stock 
                  << " | Categoria: " << lista[i].categoria
                  << std::endl;
    }
}
