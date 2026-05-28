#pragma once
#include <vector>
#include <string>
#include "../dto/ClienteDTO.h"

class ClienteView {
public:
    ClienteView();
    int mostrarMenuClientes();
    void getDadosCriarCliente(int& nif, std::string& nome);
    int getNifCliente(const std::string& acao);
    void printListaClientes(const std::vector<ClienteDTO>& lista);
};
