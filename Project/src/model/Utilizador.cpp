#include "../../include/model/Utilizador.h"

Utilizador::Utilizador(int id, std::string nome) : id(id), nome(nome) {}

int Utilizador::getId() const {
    return id;
}

std::string Utilizador::getNome() const {
    return nome;
}

void Utilizador::setNome(std::string novo_nome) {
    nome = novo_nome;
}
