#pragma once

class ItemVenda {
private:
    int idProduto;
    int quantidade;
    double preco_unitario;
    double subtotal;
public:
    ItemVenda( int idProduto int quantidade, double preco_unitario, double preco_subtotal);
    int getIdProduto() const;
    int getQuantidade() const;
    double getPrecoUnitario() const;
    double getSubtotal() const;

};




