#pragma once
#include "../../include/model/Produto.h"

namespace view {

class ProdutoView {
public:
    ProdutoView();
    void listarProduto(model::Produto& p);
};

} // namespace view
