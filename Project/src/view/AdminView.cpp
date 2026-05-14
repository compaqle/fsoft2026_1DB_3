#include "../../include/view/AdminView.h"
#include "../../include/view/CatalogoView.h"
#include "../../include/view/CategoriaView.h"
#include <iostream>

AdminView::AdminView() {}

void AdminView::mostrarMenuAdmin() {
    int opcao;
    while (true) {
        std::cout << "\n--- MENU ADMIN ---" << std::endl;
        std::cout << "1. Gerir Catalogo" << std::endl;
        std::cout << "2. Gerir Categorias" << std::endl;
        std::cout << "3. Gerir Clientes" << std::endl;
        std::cout << "4. Ver Estatisticas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "\nOpcao: ";
        while (!(std::cin >> opcao)) {
            std::cout << "Erro! Insira um numero: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            CatalogoView catalogoView;
            catalogoView.mostrarMenuCatalogo();
        } else if (opcao == 2) {
            CategoriaView categoriaView;
            categoriaView.mostrarMenuCategorias();
        } else if (opcao == 3) {
            std::cout << "Gerir Clientes - em desenvolvimento" << std::endl;
        } else if (opcao == 4) {
            std::cout << "Ver Estatisticas - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
