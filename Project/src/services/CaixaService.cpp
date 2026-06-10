#include "../../include/services/CaixaService.h"
#include "../../include/mappers/CaixaMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"

std::vector<CaixaDTO> CaixaService::getCaixas() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Caixa*> caixas = repo.getCaixas();
    std::vector<CaixaDTO> dtos;

    for (size_t i = 0; i < caixas.size(); i++) {
        dtos.push_back(CaixaMapper::toDTO(*caixas[i]));
    }
    return dtos;
}

void CaixaService::criarCaixa(std::string nome) {
    if (nome.empty()) {
        throw InvalidDataException("O nome do Caixa não pode ser vazio.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Caixa*>& caixas = repo.getCaixas();

    int novoId = 1;
    if (!caixas.empty()) {
        novoId = caixas.back()->getId() + 1;
    }

    Caixa* novoCaixa = new Caixa(novoId, nome);
    caixas.push_back(novoCaixa);
    
    repo.guardarCaixas();
}

void CaixaService::removerCaixa(int id) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Caixa*>& caixas = repo.getCaixas();
    for (size_t i = 0; i < caixas.size(); i++) {
        if (caixas[i]->getId() == id) {
            Caixa* c = caixas[i];
            caixas.erase(caixas.begin() + i);
            delete c;
            repo.guardarCaixas();
            return;
        }
    }
    throw NoDataException("Caixa: id = " + std::to_string(id) + " (nao encontrado)");
}
