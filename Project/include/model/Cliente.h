#pragma once
#include <string>
#include <vector>
#include "Ponto.h"

class Cliente {
private:
    int nif;
    std::string nome;
    Ponto pontos;
    bool isNomeValid(const std::string& nome);
    bool isNifValid(int nif);
    void setNif(int nif);

public:
    Cliente(int nif, std::string nome, int saldo_inicial = 0);
    int getNif() const;
    std::string getNome() const;
    void setNome(std::string novoNome);
    int getSaldoPontos() const;
    void ganharPontos(int valor_venda);
    void gastarPontos(int quantidade);
};
