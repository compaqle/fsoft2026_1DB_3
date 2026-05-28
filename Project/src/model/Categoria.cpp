#include "../../include/model/Categoria.h"
#include "../../include/exceptions/InvalidDataException.h"

Categoria::Categoria(int id, std::string nome, double taxa_iva) {
    this->setId(id);
    this->setNome(nome);
    this->setTaxaIva(taxa_iva);
}

int Categoria::getId() const { return id; }
std::string Categoria::getNome() const { return nome; }
double Categoria::getTaxaIva() const { return taxa_iva; }

void Categoria::setNome(std::string novoNome) {
    if (isNomeValid(novoNome)) {
        this->nome = novoNome;
    } else {
        throw InvalidDataException("Categoria: nome = " + novoNome);
    }
}

void Categoria::setTaxaIva(double novaTaxa) {
    if (isTaxaIvaValid(novaTaxa)) {
        this->taxa_iva = novaTaxa;
    } else {
        throw InvalidDataException("Categoria: taxa_iva = " + std::to_string(novaTaxa));
    }
}

void Categoria::setId(int id) {
    if (id > 0) {
        this->id = id;
    } else {
        throw InvalidDataException("Categoria: id = " + std::to_string(id));
    }
}

bool Categoria::isNomeValid(const std::string& nome) {
    return !nome.empty();
}

bool Categoria::isTaxaIvaValid(double taxa) {
    return taxa >= 0;
}
