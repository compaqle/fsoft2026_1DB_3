#pragma once
#include "../view/MainMenuView.h"
#include "../view/AdminView.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../view/CaixaView.h"
#include "../services/ProdutoService.h"
#include "../services/CategoriaService.h"

class Controller {
private:
    ProdutoService* produtoService;
    CategoriaService* categoriaService;

    MainMenuView mainMenuView;
    AdminView adminView;
    CatalogoView catalogoView;
    CategoriaView categoriaView;
    CaixaView caixaView;

    void runAdmin();
    void runCatalogo();
    void runCategorias();
    void runCaixa(int idCaixa);

public:
    Controller(ProdutoService* produtoService, CategoriaService* categoriaService);
    void run();
};
