#pragma once
#include "../view/View.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../view/ClienteView.h"
#include "../services/ProdutoService.h"
#include "../services/CategoriaService.h"
#include "../services/ClienteService.h"

class Controller {
private:
    ProdutoService* produtoService;
    CategoriaService* categoriaService;
    ClienteService* clienteService;

    View view;
    CatalogoView catalogoView;
    CategoriaView categoriaView;
    ClienteView clienteView;

    void runAdmin();
    void runCatalogo();
    void runCategorias();
    void runClientes();
    void runCaixa(int idCaixa);

public:
    Controller(ProdutoService* produtoService, CategoriaService* categoriaService, ClienteService* clienteService);
    void run();
    void adicionarProduto();
};
