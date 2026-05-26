#include "../../include/model/Caixa.h"

Caixa::Caixa(int id, const std::string& nome) : Utilizador(id, nome) {
    this->total_faturado = 0.0;
    vendaAtual = nullptr;
}

double Caixa::getTotalFaturado() const { 
    return total_faturado;
}

void Caixa::adicionarFaturacao(double valor) { 
    total_faturado += valor;
}

Venda* Caixa::getVendaAtual() const {
    return vendaAtual;
}

void Caixa::setVendaAtual(Venda*venda) {
    vendaAtual= venda;
}

void Caixa::fecharVendaAtual(Venda* venda) {
    vendaAtual = nullptr;
};
