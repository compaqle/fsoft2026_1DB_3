#pragma once
#include <vector>
#include <string>
#include "../dto/PromocaoDTO.h"

class PromocaoView {
public:
    int mostrarMenuPromocoes();
    int mostrarMenuTipoPromocao();
    void getDadosCriarPromocao(double& percentagem, std::string& data_inicio,
                                std::string& data_fim, int& id_alvo, int& tipo);
    void getDadosEditarPromocao(double& percentagem, std::string& data_inicio,
                                 std::string& data_fim);
    int getIdPromocao();
    void printListaPromocoes(const std::vector<PromocaoDTO>& lista);
};
