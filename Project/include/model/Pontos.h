#pragma once

class Pontos {
private:
    int saldo;
public:
    Pontos(int saldo_inicial = 0);
    int getSaldo();
    void adicionarPontos(int quantidade);
    void gastarPontos(int quantidade);
};
