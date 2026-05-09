#include "../../include/view/CatalogoView.h"
#include "../../include/controller/CatalogoController.h"
#include <iostream>
#include <string>

CatalogoView::CatalogoView() {}

void CatalogoView::exibirMenuCatalogo() {
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
            while (!(std::cin >> preco_base)) {
                std::cout << "Erro! Insira um numero para o preco: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            std::cout << "Stock: ";
            while (!(std::cin >> stock)) {
                std::cout << "Erro! Insira um numero inteiro para o stock: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            std::cout << "ID Categoria: ";
            while (!(std::cin >> id_categoria)) {
                std::cout << "Erro! Insira um numero para a categoria: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

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

void CatalogoView::listarProduto(Produto& p) {
}
