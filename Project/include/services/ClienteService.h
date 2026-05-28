#pragma once
#include <vector>
#include <string>
#include "../model/Cliente.h"
#include "../dto/ClienteDTO.h"
#include "../repo/SupermercadoRepository.h"

class ClienteService {
public:
    ClienteService();
    void criarCliente(int nif, std::string nome);
    void editarCliente(int nif, std::string novo_nome);
    void removerCliente(int nif);
    std::vector<ClienteDTO> getClientes();
};
