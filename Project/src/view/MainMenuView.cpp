#include "../../include/view/MainMenuView.h"
#include "../../include/view/AdminView.h"
#include "../../include/view/CaixaView.h"
#include "../../include/controller/SessaoController.h"
#include "../../include/model/Caixa.h"
#include <iostream>
#include <vector>

MainMenuView::MainMenuView() {}

void MainMenuView::mostrarMenuPrincipal() {
    std::vector<Caixa> caixas = {
        Caixa(1, "Caixa 1"),
        Caixa(2, "Caixa 2")
    };

    int opcao;
    while (true) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "       Supermercado " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "\nSelecione o perfil:" << std::endl;
        std::cout << "  0. ADMIN" << std::endl;

        for (int i = 0; i < (int)caixas.size(); i++) {
            std::cout << "  " << (i + 1) << ". CAIXA: " << caixas[i].getNome() << std::endl;
        }

        std::cout << "\nOpcao: ";
        while (!(std::cin >> opcao)) {
            std::cout << "Erro! Insira um numero: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        if (opcao == 0) {
            SessaoController sessao("ADMIN");
            AdminView adminView;
            adminView.mostrarMenuAdmin();
        } else if (opcao >= 1 && opcao <= caixas.size()) {
            SessaoController sessao("CAIXA", caixas[opcao - 1].getId());
            CaixaView caixaView;
            caixaView.mostrarMenuCaixa();
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

