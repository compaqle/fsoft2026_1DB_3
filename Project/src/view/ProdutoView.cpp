#include "../../include/view/ProdutoView.h"
#include <iostream>

ProdutoView::ProdutoView() {}

void ProdutoView::listarProduto(Produto& p) {
    std::cout << "ID: " << p.getId() << " | Nome: " << p.getNome() << " | Preco: " << p.getPrecoBase() << " Euro" << std::endl;
}
