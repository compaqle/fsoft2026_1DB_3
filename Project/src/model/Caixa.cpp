#include "../../include/model/Caixa.h"

Caixa::Caixa(int id, std::string nome) {
    this->id = id;
    this->nome = nome;
    this->total_faturado = 0.0;
}

int Caixa::getId() { return id; }
std::string Caixa::getNome() { return nome; }
double Caixa::getTotalFaturado() { return total_faturado; }
void Caixa::adicionarFaturacao(double valor) { total_faturado += valor; }
