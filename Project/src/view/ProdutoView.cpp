#include "../../include/view/ProdutoView.h"
#include "../../include/controller/CatalogoController.h"
#include <iostream>
#include <string>

ProdutoView::ProdutoView() {}

void ProdutoView::exibirMenuCatalogo() {
    CatalogoController controller;

    int opcao;
    while (true) {
        std::cout << "\n--- GERIR CATALOGO ---" << std::endl;
        std::cout << "1. Criar Produto" << std::endl;
        std::cout << "2. Listar Produtos" << std::endl;
        std::cout << "3. Editar Produto" << std::endl;
        std::cout << "4. Remover Produto" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        std::cout << "\nOpcao: ";
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::string nome;
            double preco_base;
            int stock, id_categoria;

            std::cout << "Nome: ";
            std::getline(std::cin, nome);

            std::cout << "Preco base: ";
            std::cin >> preco_base;

            std::cout << "Stock: ";
            std::cin >> stock;

            std::cout << "ID Categoria: ";
            std::cin >> id_categoria;

            controller.criarProduto(nome, preco_base, stock, id_categoria);
            std::cout << "Produto criado com sucesso!" << std::endl;

        } else if (opcao == 2) {
            std::cout << "Listar Produtos - em desenvolvimento" << std::endl;
        } else if (opcao == 3) {
            std::cout << "Editar Produto - em desenvolvimento" << std::endl;
        } else if (opcao == 4) {
            std::cout << "Remover Produto - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void ProdutoView::listarProduto(Produto& p) {
}
