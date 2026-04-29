#include "../../include/model/Cliente.h"

namespace model {

Cliente::Cliente(int nif, std::string nome, int pontos) {
    this->nif = nif;
    this->nome = nome;
    this->pontos = pontos;
}

} // namespace model
