#pragma once
#include <string>

namespace model {

class Cliente {
private:
    int nif;
    std::string nome;
    int pontos;

public:
    Cliente(int nif, std::string nome, int pontos = 0);
};

} // namespace model
