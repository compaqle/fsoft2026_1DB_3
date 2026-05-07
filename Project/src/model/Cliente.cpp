#include "../../include/model/Cliente.h"

Cliente::Cliente(int nif, std::string nome, int saldo_inicial) 
    : pontos(saldo_inicial) {
    this->nif = nif;
    this->nome = nome;
}

int Cliente::getNif() { return nif; }
std::string Cliente::getNome() { return nome; }

int Cliente::getSaldoPontos() {
    return pontos.getQuantidade();
}

void Cliente::ganharPontos(int valor_venda) {
    int novos_pontos = valor_venda / 10;
    pontos.adicionarPontos(novos_pontos);
}
