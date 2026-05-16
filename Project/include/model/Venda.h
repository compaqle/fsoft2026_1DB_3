#pragma once
#include <string>
#include <vector>
#include "ItemVenda.h"

class Venda {
private:
    int id;
    std::string nifCliente;
    std::string data_hora;
    double total;
    std::string metodo_pagamento;
    std::vector<ItemVenda> vendas;

public:
    Venda(int id, int nif_cliente);
    int getId() const;
    std::string getNifCliente() const;
    std::string getDataHora() const;
    double getTotal() const;
    std::string getMetodoPagamento() const;
    std::vector<ItemVenda> getVendas() const;
};
