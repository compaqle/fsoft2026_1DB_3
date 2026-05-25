#pragma once
#include <string>
#include <vector>
#include "Ponto.h"

class Cliente {
private:
    std::string nif;
    std::string nome;
    Ponto pontos;

public:
    Cliente(int nif, std::string nome, int saldo_inicial = 0);
    std::string getNif() const;
    std::string getNome() const;
    int getSaldoPontos() const;
    void ganharPontos(int valor_venda) ;
    void gastarPontos(int quantidade);

};
