#pragma once
#include <string>

class Caixa {
private:
    int id;
    std::string nome;
    double total_faturado;

public:
    Caixa(int id, std::string nome);
    int getId();
    std::string getNome();
    double getTotalFaturado();
    void adicionarFaturacao(double valor);
};
