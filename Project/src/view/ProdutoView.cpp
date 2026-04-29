#include "../../include/view/ProdutoView.h"
#include <iostream>

namespace view {

ProdutoView::ProdutoView() {}

void ProdutoView::listarProduto(model::Produto& p) {
    // Aqui usaremos os getters que criaste no Produto.h
    std::cout << "ID: " << p.getId() << " | Nome: " << p.getNome() << " | Preco: " << p.getPrecoBase() << " Euro" << std::endl;
}

} // namespace view
