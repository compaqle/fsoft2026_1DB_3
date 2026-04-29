#include "../../include/model/Categoria.h"

namespace model {

Categoria::Categoria(int id, std::string nome, double taxa_iva) {
    this->id = id;
    this->nome = nome;
    this->taxa_iva = taxa_iva;
}

} // namespace model
