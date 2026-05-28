#pragma once
#include <string>

class Categoria {
private:
    int id;
    std::string nome;
    double taxa_iva;

    bool isNomeValid(const std::string& nome);
    bool isTaxaIvaValid(double taxa);
    void setId(int id);

public:
    Categoria(int id, std::string nome, double taxa_iva);
    int getId() const;
    std::string getNome() const;
    double getTaxaIva() const;

    void setNome(std::string novoNome);
    void setTaxaIva(double novaTaxa);
};
