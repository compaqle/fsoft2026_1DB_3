#pragma once
#include <string>
#include "Pontos.h"

class Cliente {
private:
    int nif;
    std::string nome;
    Pontos pontos; // Agora PONTOS é uma entidade (objeto) dentro do Cliente

public:
    Cliente(int nif, std::string nome, int saldo_inicial = 0);
    int getNif();
    std::string getNome();
    int getSaldoPontos();
    void ganharPontos(int valor_venda);
};
