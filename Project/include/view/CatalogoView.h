#pragma once
#include "../controller/CatalogoController.h"
#include "../../include/model/Produto.h"

class CatalogoView {
public:
    CatalogoView();
    void mostrarMenuCatalogo(CatalogoController& controller);
    void listarProduto(Produto& p);
};
