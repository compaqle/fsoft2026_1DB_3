#include "../../include/controller/Controller.h"
#include <iostream>

Controller::Controller(CatalogoController& catalogoController, CategoriaController& categoriaController) : catalogoController(catalogoController), categoriaController(categoriaController) {
}

void Controller::run() {
    while (true) {
        int op = mainMenuView.mostrarMenuPrincipal();

        if (op == 0) {
            runAdmin();
        } else if (op >= 1) {
            runCaixa(op);
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void Controller::runAdmin() {
    while (true) {
        int op = adminView.mostrarMenuAdmin();

        if (op == 0) {
            return;
        } else if (op == 1) {
            catalogoView.mostrarMenuCatalogo(catalogoController);
        } else if (op == 2) {
            categoriaView.mostrarMenuCategorias(categoriaController);
        } else if (op == 3) {
            std::cout << "Gerir Clientes - em desenvolvimento" << std::endl;
        } else if (op == 4) {
            std::cout << "Ver Estatisticas - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void Controller::runCaixa(int idCaixa) {
    while (true) {
        int op = caixaView.mostrarMenuCaixa();

        if (op == 0) {
            return;
        } else if (op == 1) {
            std::cout << "Realizar Venda - em desenvolvimento" << std::endl;
        } else if (op == 2) {
            std::cout << "Consultar Preco - em desenvolvimento" << std::endl;
        } else if (op == 3) {
            std::cout << "Consultar Pontos Cliente - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
