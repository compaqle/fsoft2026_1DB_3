#include "../../include/model/Venda.h"
#include "../../include/model/Cliente.h"

Venda::Venda(int id, Cliente* cliente) {
    this->id = id;
    this->cliente = cliente;
    this->total = 0.0;
}

int Venda::getId() const { return id; }
Cliente* Venda::getCliente() const { return cliente; }
std::string Venda::getDataHora() const { return data_hora; }
double Venda::getTotal() const { return total; }
std::string Venda::getMetodoPagamento() const { return metodo_pagamento; }
std::vector<ItemVenda> Venda::getVendas() const { return vendas; }

void Venda::setDataHora(const std::string& data_hora) {
    this->data_hora = data_hora;
}

void Venda::setTotal(double total) {
    this->total = total;
}

void Venda::setMetodoPagamento(const std::string& metodo) {
    this->metodo_pagamento = metodo;
}

void Venda::adicionarItem(const ItemVenda& item) {
    this->vendas.push_back(item);
}