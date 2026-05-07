#pragma once
#include <string>
#include "Ponto.h"

class Cliente {
private:
    int nif;
    std::string nome;
    Ponto pontos;

public:
    Cliente(int nif, std::string nome, int saldo_inicial = 0);
    int getNif();
    std::string getNome();
    int getSaldoPontos();
    void ganharPontos(int valor_venda);
};
