#pragma once
#include "Utilizador.h"

class Caixa : public Utilizador {
private:
    double total_faturado;

public:
    Caixa(int id, std::string nome);
    
    double getTotalFaturado() const;
    void adicionarFaturacao(double valor);
};
