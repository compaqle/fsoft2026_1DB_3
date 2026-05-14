#include "../../include/view/CategoriaView.h"
#include "../../include/controller/CategoriaController.h"
#include <iostream>
#include <string>

CategoriaView::CategoriaView() {}

void CategoriaView::mostrarMenuCategorias() {
    CategoriaController controller;

    int opcao;
    while (true) {
        std::cout << "\n--- GERIR CATEGORIAS ---" << std::endl;
        std::cout << "1. Criar Categoria" << std::endl;
        std::cout << "2. Listar Categorias" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        std::cout << "\nOpcao: ";
        while (!(std::cin >> opcao)) {
            std::cout << "Erro! Insira um numero: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cin.ignore();

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::string nome;
            double taxa_iva;

            std::cout << "Nome da Categoria: ";
            std::getline(std::cin, nome);

            std::cout << "Taxa de IVA (ex: 0.23 para 23%): ";
            while (!(std::cin >> taxa_iva)) {
                std::cout << "Erro! Escreva um numero decimal (ex: 0.23): ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            controller.criarCategoria(nome, taxa_iva);
            std::cout << "Categoria criada com sucesso!" << std::endl;

        } else if (opcao == 2) {
            std::vector<Categoria>& lista = controller.getCategorias();
            if (lista.empty()) {
                std::cout << "\nNão existem categorias registadas." << std::endl;
            } else {
                std::cout << "\n--- LISTA DE CATEGORIAS ---" << std::endl;
                for (int i = 0; i < (int)lista.size(); i++) {
                    std::cout << "ID: " << lista[i].getId() 
                              << " | Nome: " << lista[i].getNome() 
                              << " | IVA: " << (lista[i].getTaxaIva() * 100) << "%" << std::endl;
                }
            }
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}