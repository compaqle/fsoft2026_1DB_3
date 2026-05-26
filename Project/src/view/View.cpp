#include "../../include/view/View.h"
#include "../../include/view/Utils.h"
#include "../../include/model/Caixa.h"
#include "../../include/model/Admin.h"
#include <iostream>
#include <vector>

View::View() {}

int View::menuPrincipal() {
    std::vector<Caixa> caixas = {
        Caixa(1, "Caixa 1"),
        Caixa(2, "Caixa 2")
    };

    std::cout << "\n========================================" << std::endl;
    std::cout << "       Supermercado " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\nSelecione o perfil:" << std::endl;
    std::cout << "  " << Admin::ADMIN_DEFAULT_ID << ". ADMIN" << std::endl;
    std::cout << " -1. Sair" << std::endl;
    
    for (size_t i = 0; i < caixas.size(); i++) {
        std::cout << "  " << (i + 1) << ". CAIXA: " << caixas[i].getNome() << std::endl;
    }

    int opcao = Utils::lerInt("\nOpcao: ");

    if (opcao == Admin::ADMIN_DEFAULT_ID) {
        return 0;
    } else if (opcao >= 1 && (size_t)opcao <= caixas.size()) {
        return opcao;
    }
    return -1;
}

int View::menuAdmin() {
    std::cout << "\n--- MENU ADMIN ---" << std::endl;
    std::cout << "1. Gerir Catalogo" << std::endl;
    std::cout << "2. Gerir Categorias" << std::endl;
    std::cout << "3. Gerir Clientes" << std::endl;
    std::cout << "4. Ver Estatisticas" << std::endl;
    std::cout << "0. Sair" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

int View::menuCaixa() {
    std::cout << "\n--- MENU CAIXA ---" << std::endl;
    std::cout << "1. Realizar Venda" << std::endl;
    std::cout << "2. Consultar Preco" << std::endl;
    std::cout << "3. Consultar Pontos Cliente" << std::endl;
    std::cout << "0. Sair" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

void View::printMensagem(const std::string& msg) {
    std::cout << msg << std::endl;
}
