#include "../../include/model/ItemVenda.h"

ItemVenda::ItemVenda(Produto* produto, int quantidade, double preco_unitario, double subtotal) {
    this->produto = produto;
    this->quantidade = quantidade;
    this->preco_unitario = preco_unitario;
    this->subtotal = subtotal;
}

Produto* ItemVenda::getProduto() const { return produto; }
int ItemVenda::getQuantidade() const { return quantidade; }
double ItemVenda::getPrecoUnitario() const { return preco_unitario; }
double ItemVenda::getSubtotal() const { return subtotal; }
