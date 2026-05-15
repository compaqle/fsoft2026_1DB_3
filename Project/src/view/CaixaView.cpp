#include "../../include/view/CaixaView.h"
#include "../../include/view/Utils.h"
#include <iostream>

CaixaView::CaixaView() {}

int CaixaView::mostrarMenuCaixa() {
    std::cout << "\n--- MENU CAIXA ---" << std::endl;
    std::cout << "1. Realizar Venda" << std::endl;
    std::cout << "2. Consultar Preco" << std::endl;
    std::cout << "3. Consultar Pontos Cliente" << std::endl;
    std::cout << "0. Sair" << std::endl;

    return Utils::lerInt("\nOpcao: ");
}
