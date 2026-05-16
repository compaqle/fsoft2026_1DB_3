#pragma once
#include <string>
#include <vector>
#include "Itemvenda.h"

class Venda {
private:
    int id;
    int idCaixa;
    std::string nifCliente;
    std::string data_hora
    double total;
    std::string metodo_pagamento;
    std::vector<Itemvenda> vendas;



public:
    Venda(int id, int nif_cliente);
    int getId() const;
    int getIdCaixa() const;
    std::string getNifCliente() const;
    std::string getDataHora const();
    double getTotal() const;
    std::string getMetodoPagamento() const;
    std::vector<Itemvenda> getVendas() const;

};
