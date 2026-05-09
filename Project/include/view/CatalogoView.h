#pragma once
#include "../../include/model/Produto.h"

class CatalogoView {
public:
    CatalogoView();
    void exibirMenuCatalogo();
    void listarProduto(Produto& p);
};
