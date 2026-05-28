#include "../../include/model/Cliente.h"
#include "../../include/exceptions/InvalidDataException.h"

Cliente::Cliente(int nif, std::string nome, int saldo_inicial) 
    : pontos(saldo_inicial) {
    this->setNif(nif);
    this->setNome(nome);
}

int Cliente::getNif() const { return nif; }
std::string Cliente::getNome() const { return nome; }

void Cliente::setNome(std::string novoNome) {
    if (isNomeValid(novoNome)) {
        this->nome = novoNome;
    } else {
        throw InvalidDataException("Cliente: nome = " + novoNome);
    }
}

void Cliente::setNif(int nif) {
    if (isNifValid(nif)) {
        this->nif = nif;
    } else {
        throw InvalidDataException("Cliente: nif = " + std::to_string(nif));
    }
}

bool Cliente::isNomeValid(const std::string& nome) {
    return !nome.empty();
}

bool Cliente::isNifValid(int nif) {
    return nif > 0;
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
