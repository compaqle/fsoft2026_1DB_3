#include "../../include/model/Cliente.h"

Cliente::Cliente(int nif, std::string nome, int saldo_inicial) 
    : pontos(saldo_inicial) { // Inicializa a entidade Pontos
    this->nif = nif;
    this->nome = nome;
}

int Cliente::getNif() { return nif; }
std::string Cliente::getNome() { return nome; }

int Cliente::getSaldoPontos() {
    return pontos.getSaldo();
}

void Cliente::ganharPontos(int valor_venda) {
    // Regra: 1 ponto por cada 10 euros (conforme o teu RF13)
    int novos_pontos = valor_venda / 10;
    pontos.adicionarPontos(novos_pontos);
}
