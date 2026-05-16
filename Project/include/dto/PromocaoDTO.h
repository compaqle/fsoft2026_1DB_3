#pragma once
#include <string>

struct PromocaoDTO {
    int id;
    double percentagem;
    std::string dataInicio;
    std::string dataFim;
    std::string nomeCategoria;
    std::string nomeProduto;
};
