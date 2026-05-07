#pragma once

class Ponto {
private:
    int quantidade;
public:
    Ponto(int quantidade_inicial = 0);
    int getQuantidade();
    void adicionarPontos(int quantidade);
    void gastarPontos(int quantidade);
};
