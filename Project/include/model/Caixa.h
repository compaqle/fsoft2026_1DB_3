#pragma once
#include "Utilizador.h"

class Caixa : public Utilizador {
private:
    double total_faturado;
    Venda* vendaAtual;

public:
    Caixa(int id,  const std::string& nome);
    
    double getTotalFaturado() const;
    void adicionarFaturacao(double valor);

    Venda* getVendaAtual() const;
    void setVendaAtual(Venda* venda);
    void fecharVendaAtual(Venda* venda);
};
