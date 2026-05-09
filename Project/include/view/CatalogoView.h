#pragma once
#include "../../include/model/Produto.h"

class CatalogoView {
public:
    CatalogoView();
    void mostrarMenuCatalogo();
    void listarProduto(Produto& p);
};
