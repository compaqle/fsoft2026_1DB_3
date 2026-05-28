#include "../../include/view/ClienteView.h"
#include "../../include/view/Utils.h"
#include <iostream>

ClienteView::ClienteView() {}

int ClienteView::mostrarMenuClientes() {
    std::cout << "\n--- GERIR CLIENTES ---" << std::endl;
    std::cout << "1. Criar Cliente" << std::endl;
    std::cout << "2. Listar Clientes" << std::endl;
    std::cout << "3. Editar Cliente" << std::endl;
    std::cout << "4. Remover Cliente" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

void ClienteView::getDadosCriarCliente(int& nif, std::string& nome) {
    nif = Utils::lerInt("NIF do Cliente: ");
    nome = Utils::lerString("Nome do Cliente: ");
}

int ClienteView::getNifCliente(const std::string& acao) {
    std::string msg = "NIF do cliente a " + acao + ": ";
    return Utils::lerInt(msg);
}

void ClienteView::printListaClientes(const std::vector<ClienteDTO>& lista) {
    if (lista.empty()) {
        std::cout << "\nNao existem clientes registados." << std::endl;
        return;
    }
    std::cout << "\n--- LISTA DE CLIENTES ---" << std::endl;
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << "NIF: " << lista[i].nif
                  << " | Nome: " << lista[i].nome
                  << " | Pontos: " << lista[i].pontos << std::endl;
    }
}
