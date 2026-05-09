#pragma once
#include "../../include/model/Produto.h"

class ProdutoView {
public:
    ProdutoView();
    void exibirMenuCatalogo();
    void listarProduto(Produto& p);
};
