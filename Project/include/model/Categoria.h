#pragma once
#include <string>

class Categoria {
private:
    int id;
    std::string nome;
    double taxa_iva;

public:
    Categoria(int id, std::string nome, double taxa_iva);
    int getId() const;
    std::string getNome() const;
    double getTaxaIva() const;
};
