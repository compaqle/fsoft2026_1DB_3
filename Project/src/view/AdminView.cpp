#include "../../include/view/AdminView.h"
#include "../../include/view/Utils.h"
#include <iostream>

AdminView::AdminView() {}

int AdminView::mostrarMenuAdmin() {
    std::cout << "\n--- MENU ADMIN ---" << std::endl;
    std::cout << "1. Gerir Catalogo" << std::endl;
    std::cout << "2. Gerir Categorias" << std::endl;
    std::cout << "3. Gerir Clientes" << std::endl;
    std::cout << "4. Ver Estatisticas" << std::endl;
    std::cout << "0. Sair" << std::endl;

    return Utils::lerInt("\nOpcao: ");
}

void AdminView::printMensagem(const std::string& msg) {
    std::cout << msg << std::endl;
}
