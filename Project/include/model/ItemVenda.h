#pragma once

class ItemVenda {
private:
    int quantidade;
    double preco_unitario;
    double subtotal;
public:
    ItemVenda(int quantidade, double preco_unitario, double preco_subtotal);
    int getQuantidade() const;
    double getPreco() const;
    double getSubtotal() const;

};




