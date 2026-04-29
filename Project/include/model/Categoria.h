#pragma once
#include <string>

namespace model {

class Categoria {
private:
    int id;
    std::string nome;
    double taxa_iva;

public:
    Categoria(int id, std::string nome, double taxa_iva);
};

} // namespace model
