#include "../../include/view/AdminView.h"
#include <iostream>

AdminView::AdminView() {}

void AdminView::exibirMenuAdmin() {
    int opcao;
    while (true) {
        std::cout << "\n--- MENU ADMIN ---" << std::endl;
        std::cout << "1. Gerir Catalogo" << std::endl;
        std::cout << "2. Gerir Clientes" << std::endl;
        std::cout << "3. Ver Estatisticas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "\nOpcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::cout << "Gerir Catalogo - em desenvolvimento" << std::endl;
        } else if (opcao == 2) {
            std::cout << "Gerir Clientes - em desenvolvimento" << std::endl;
        } else if (opcao == 3) {
            std::cout << "Ver Estatisticas - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
