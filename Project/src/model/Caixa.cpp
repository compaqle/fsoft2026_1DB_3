#include "../../include/model/Caixa.h"

namespace model {

Caixa::Caixa(int id, std::string nome) {
    this->id = id;
    this->nome = nome;
    this->total_faturado = 0.0;
}

} // namespace model
