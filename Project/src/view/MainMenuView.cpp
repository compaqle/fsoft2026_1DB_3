#include "../../include/view/MainMenuView.h"
#include "../../include/view/AdminView.h"
#include "../../include/view/CaixaView.h"
#include "../../include/controller/SessaoController.h"
#include "../../include/model/Caixa.h"
#include <iostream>
#include <vector>

MainMenuView::MainMenuView() {}

void MainMenuView::exibirMenuPrincipal() {
    std::vector<Caixa> caixas = {
        Caixa(1, "Caixa 1"),
        Caixa(2, "Caixa 2")
    };

    int opcao;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "  Supermercado " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "\nSelecione o perfil:" << std::endl;
        std::cout << "  0. ADMIN" << std::endl;

        for (size_t i = 0; i < caixas.size(); i++) {
            std::cout << "  " << (i + 1) << ". CAIXA: " << caixas[i].getNome() << std::endl;
        }

        std::cout << "\nOpcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            SessaoController sessao("ADMIN");
            AdminView adminView;
            adminView.exibirMenuAdmin();
        } else if (opcao >= 1 && opcao <= (int)caixas.size()) {
            SessaoController sessao("CAIXA", caixas[opcao - 1].getId());
            CaixaView caixaView;
            caixaView.exibirMenuCaixa();
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    } while (true);
}
