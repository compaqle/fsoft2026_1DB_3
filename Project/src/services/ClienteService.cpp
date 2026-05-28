#include "../../include/services/ClienteService.h"
#include "../../include/mappers/ClienteMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/exceptions/DuplicatedDataException.h"

ClienteService::ClienteService() {}

void ClienteService::criarCliente(int nif, std::string nome) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Cliente*>& clientes = repo.getClientes();
    
    for (size_t i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getNif() == nif) {
            throw DuplicatedDataException("Cliente: nif = " + std::to_string(nif) + " (ja existe)");
        }
    }

    // O construtor de Cliente agora trata as validacoes de nif > 0 e nome nao vazio
    Cliente* novo = new Cliente(nif, nome);
    clientes.push_back(novo);
    repo.guardarClientes();
}

void ClienteService::editarCliente(int nif, std::string novo_nome) {
    if (novo_nome == "-1") {
        return;
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Cliente*>& clientes = repo.getClientes();
    
    Cliente* clienteParaEditar = NULL;
    for (size_t i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getNif() == nif) {
            clienteParaEditar = clientes[i];
            break;
        }
    }

    if (clienteParaEditar == NULL) {
        throw NoDataException("Cliente: nif = " + std::to_string(nif) + " (nao encontrado)");
    }

    // O setNome trata a validacao
    clienteParaEditar->setNome(novo_nome);
    repo.guardarClientes();
}

void ClienteService::removerCliente(int nif) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Cliente*>& clientes = repo.getClientes();
    
    for (size_t i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getNif() == nif) {
            Cliente* c = clientes[i];
            clientes.erase(clientes.begin() + i);
            delete c;
            repo.guardarClientes();
            return;
        }
    }
    throw NoDataException("Cliente: nif = " + std::to_string(nif) + " (nao encontrado)");
}

std::vector<ClienteDTO> ClienteService::getClientes() {
    std::vector<Cliente*>& clientes = SupermercadoRepository::getInstance().getClientes();
    std::vector<ClienteDTO> dtos;
    for (size_t i = 0; i < clientes.size(); i++) {
        dtos.push_back(ClienteMapper::toDTO(*clientes[i]));
    }
    return dtos;
}
