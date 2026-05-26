#pragma once
#include "../view/View.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../services/ProdutoService.h"
#include "../services/CategoriaService.h"

class Controller {
private:
    ProdutoService* produtoService;
    CategoriaService* categoriaService;

    View view;
    CatalogoView catalogoView;
    CategoriaView categoriaView;

    void runAdmin();
    void runCatalogo();
    void runCategorias();
    void runCaixa(int idCaixa);

public:
    Controller(ProdutoService* produtoService, CategoriaService* categoriaService);
    void run();
    void adicionarProduto();
};
