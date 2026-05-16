#include "../../include/model/Ponto.h"

Ponto::Ponto(int quantidade_inicial) {
    this->quantidade = quantidade_inicial;
}

int Ponto::getQuantidade() const {
    return quantidade;
}

void Ponto::adicionarPontos(int quantidade) {
    this->quantidade += quantidade;
}

void Ponto::gastarPontos(int quantidade) {
    if (this->quantidade >= quantidade) {
        this->quantidade -= quantidade;
    }
}
