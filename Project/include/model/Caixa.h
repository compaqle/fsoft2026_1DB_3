#pragma once
#include <string>

namespace model {

class Caixa {
private:
    int id;
    std::string nome;
    double total_faturado;

public:
    Caixa(int id, std::string nome);
};

} // namespace model
