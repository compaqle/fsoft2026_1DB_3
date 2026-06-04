#pragma once
#include <vector>
#include <string>
#include "../dto/CaixaDTO.h"
#include "../repo/SupermercadoRepository.h"

class CaixaService {
public:
    std::vector<CaixaDTO> getCaixas();
    void criarCaixa(std::string nome);
    void removerCaixa(int id);
};
