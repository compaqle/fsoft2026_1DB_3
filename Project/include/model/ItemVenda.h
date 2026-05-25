#pragma once

class Produto;

class ItemVenda {
private:
    Produto* produto;
    int quantidade;
    double preco_unitario;
    double subtotal;

public:
    ItemVenda(Produto* produto, int quantidade, double preco_unitario, double subtotal);
    Produto* getProduto() const;
    int getQuantidade() const;
    double getPrecoUnitario() const;
    double getSubtotal() const;
};
