#include "../../include/model/Cliente.h"

Cliente::Cliente(int nif, std::string nome, int saldo_inicial) 
    : pontos(saldo_inicial) {
    this->nif = nif;
    this->nome = nome;
}

int Cliente::getNif() const { return nif; }
std::string Cliente::getNome() const { return nome; }

void Cliente::setNome(std::string novoNome) {
    this->nome = novoNome;
}

int Cliente::getSaldoPontos() const {
    return pontos.getQuantidade();
}

void Cliente::ganharPontos(int valor_venda) {
    int novos_pontos = valor_venda / 10;
    pontos.adicionarPontos(novos_pontos);
}

void Cliente::gastarPontos(int quantidade) {
    pontos.gastarPontos(quantidade);
}
