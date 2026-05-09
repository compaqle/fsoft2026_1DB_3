#include "../../include/view/CaixaView.h"
#include <iostream>

CaixaView::CaixaView() {}

void CaixaView::mostrarMenuCaixa() {
    int opcao;
    while (true) {
        std::cout << "\n--- MENU CAIXA ---" << std::endl;
        std::cout << "1. Realizar Venda" << std::endl;
        std::cout << "2. Consultar Preco" << std::endl;
        std::cout << "3. Consultar Pontos Cliente" << std::endl;
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
            std::cout << "Realizar Venda - em desenvolvimento" << std::endl;
        } else if (opcao == 2) {
            std::cout << "Consultar Preco - em desenvolvimento" << std::endl;
        } else if (opcao == 3) {
            std::cout << "Consultar Pontos Cliente - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
