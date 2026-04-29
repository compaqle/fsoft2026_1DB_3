#include "../../include/view/AdminView.h"
#include <iostream>

namespace view {

AdminView::AdminView() {}

void AdminView::exibirMenuAdmin() {
    std::cout << "\n--- MENU ADMINISTRADOR ---" << std::endl;
    std::cout << "1. Gerir Catalogo" << std::endl;
    std::cout << "2. Gerir Clientes" << std::endl;
    std::cout << "3. Ver Estatisticas" << std::endl;
    std::cout << "0. Sair" << std::endl;
}

} // namespace view
