#pragma once
#include <vector>
#include <string>
#include "../dto/CaixaDTO.h"

class CaixaView {
public:
    int mostrarMenuCaixas();
    void getDadosCriarCaixa(std::string& nome);
    void printListaCaixas(const std::vector<CaixaDTO>& caixas);
    int getIdCaixa();
    int getIdCaixaEditar();
};
