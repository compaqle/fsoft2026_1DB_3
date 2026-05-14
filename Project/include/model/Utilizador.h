#pragma once
#include <string>

class Utilizador {
protected:
    int id;
    std::string nome;

public:
    Utilizador(int id, std::string nome);

    int getId() const;
    std::string getNome() const;
};
