#include "../../include/model/Categoria.h"

Categoria::Categoria(int id, std::string nome, double taxa_iva) {
    this->id = id;
    this->nome = nome;
    this->taxa_iva = taxa_iva;
}

int Categoria::getId() const { return id; }
std::string Categoria::getNome() const { return nome; }
double Categoria::getTaxaIva() const { return taxa_iva; }
