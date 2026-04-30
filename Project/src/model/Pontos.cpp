#include "../../include/model/Pontos.h"

Pontos::Pontos(int saldo_inicial) {
    this->saldo = saldo_inicial;
}

int Pontos::getSaldo() {
    return saldo;
}

void Pontos::adicionarPontos(int quantidade) {
    this->saldo += quantidade;
}

void Pontos::gastarPontos(int quantidade) {
    if (this->saldo >= quantidade) {
        this->saldo -= quantidade;
    }
}
