#pragma once
#include <string>
#include <vector>
#include "ItemVenda.h"

class Cliente;

class Venda {
private:
    int id;
    Cliente* cliente;
    std::string data_hora;
    double total;
    std::string metodo_pagamento;
    std::vector<ItemVenda> vendas;

public:
    Venda(int id, Cliente* cliente);

    int getId() const;
    Cliente* getCliente() const;
    std::string getDataHora() const;
    double getTotal() const;
    std::string getMetodoPagamento() const;
    std::vector<ItemVenda> getVendas() const;

    void setDataHora(const std::string& data_hora);
    void setTotal(double total);
    void setMetodoPagamento(const std::string& metodo);
    void adicionarItem(const ItemVenda& item);
};
