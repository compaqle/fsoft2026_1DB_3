#include "../../include/model/Caixa.h"

Caixa::Caixa(int id, const std::string& nome) : Utilizador(id, nome) {
    this->total_faturado = 0.0;
}

double Caixa::getTotalFaturado() const { 
    return total_faturado;
}

void Caixa::adicionarFaturacao(double valor) { 
    total_faturado += valor;
}
