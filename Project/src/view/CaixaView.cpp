#include "../../include/view/CaixaView.h"
#include "../../include/view/Utils.h"
#include <iostream>

int CaixaView::mostrarMenuCaixas() {
    std::cout << "\n--- Gestao de Caixas ---" << std::endl;
    std::cout << "1. Registar Caixa" << std::endl;
    std::cout << "2. Listar Caixas" << std::endl;
    std::cout << "3. Remover Caixa" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("Opcao: ");
}

void CaixaView::getDadosCriarCaixa(std::string& nome) {
    nome = Utils::lerString("Nome do novo Caixa: ");
}

void CaixaView::printListaCaixas(const std::vector<CaixaDTO>& caixas) {
    std::cout << "\n--- Lista de Caixas ---" << std::endl;
    if (caixas.empty()) {
        std::cout << "Não existem caixas registados." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < caixas.size(); i++) {
        std::cout << "ID: " << caixas[i].id << " | Nome: " << caixas[i].nome << std::endl;
    }
}

int CaixaView::getIdCaixa() {
    return 0; // Esqueleto a implementar
}
