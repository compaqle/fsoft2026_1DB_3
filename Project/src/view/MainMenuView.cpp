#include "../../include/view/MainMenuView.h"
#include "../../include/view/Utils.h"
#include "../../include/model/Caixa.h"
#include "../../include/model/Admin.h"
#include <iostream>
#include <vector>

MainMenuView::MainMenuView() {}

int MainMenuView::mostrarMenuPrincipal() {
    std::vector<Caixa> caixas = {
        Caixa(1, "Caixa 1"),
        Caixa(2, "Caixa 2")
    };

    std::cout << "\n========================================" << std::endl;
    std::cout << "       Supermercado " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\nSelecione o perfil:" << std::endl;
    std::cout << "  " << Admin::ADMIN_DEFAULT_ID << ". ADMIN" << std::endl;

    for (int i = 0; i < (int)caixas.size(); i++) {
        std::cout << "  " << (i + 1) << ". CAIXA: " << caixas[i].getNome() << std::endl;
    }

    int opcao = Utils::lerInt("\nOpcao: ");

    if (opcao == Admin::ADMIN_DEFAULT_ID) {
        return 0;
    } else if (opcao >= 1 && opcao <= (int)caixas.size()) {
        return opcao;
    }
    return -1;
}

void MainMenuView::printMensagem(const std::string& msg) {
    std::cout << msg << std::endl;
}
