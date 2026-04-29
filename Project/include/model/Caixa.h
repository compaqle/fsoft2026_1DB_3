#pragma once
#include <string>

class Caixa {
private:
    int id;
    std::string nome;
    double total_faturado;

public:
    Caixa(int id, std::string nome);
};
