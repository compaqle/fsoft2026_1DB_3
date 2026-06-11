#include "../../include/view/View.h"
#include "../../include/view/Utils.h"
#include <iostream>
#include <vector>

View::View() {}

int View::menuPrincipal(const std::vector<CaixaDTO>& caixas) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       Supermercado " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\nSelecione o perfil:" << std::endl;
    std::cout << "  0. ADMIN" << std::endl;
    std::cout << " -1. Sair" << std::endl;
    
    for (size_t i = 0; i < caixas.size(); i++) {
        std::cout << "  " << caixas[i].id << ". CAIXA: " << caixas[i].nome << std::endl;
    }

    int opcao = Utils::lerInt("\nOpcao: ");

    if (opcao == 0) {
        return 0;
    }
    if (opcao == -1) {
        return -1;
    }
    
    for (size_t i = 0; i < caixas.size(); i++) {
        if (opcao == caixas[i].id) {
            return opcao;
        }
    }
    
    return -2; // Opcao invalida
}

int View::menuAdmin() {
    std::cout << "\n--- MENU ADMIN ---" << std::endl;
    std::cout << "1. Gerir Catalogo" << std::endl;
    std::cout << "2. Gerir Categorias" << std::endl;
    std::cout << "3. Gerir Clientes" << std::endl;
    std::cout << "4. Gerir Caixas" << std::endl;
    std::cout << "5. Ver Estatisticas" << std::endl;
    std::cout << "6. Gerir Promocoes" << std::endl;
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
