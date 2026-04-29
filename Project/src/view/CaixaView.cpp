#include "../../include/view/CaixaView.h"
#include <iostream>

namespace view {

CaixaView::CaixaView() {}

void CaixaView::exibirMenuCaixa() {
    std::cout << "\n--- MENU CAIXA ---" << std::endl;
    std::cout << "1. Realizar Venda" << std::endl;
    std::cout << "2. Consultar Preco" << std::endl;
    std::cout << "3. Consultar Pontos Cliente" << std::endl;
    std::cout << "0. Sair" << std::endl;
}

} // namespace view
