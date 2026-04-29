#pragma once
#include <string>

class Cliente {
private:
    int nif;
    std::string nome;
    int pontos;

public:
    Cliente(int nif, std::string nome, int pontos = 0);
};
