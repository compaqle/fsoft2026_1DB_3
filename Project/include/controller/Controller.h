#pragma once
#include "../view/View.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../view/ClienteView.h"
#include "../view/CaixaView.h"
#include "../services/ProdutoService.h"
#include "../services/CategoriaService.h"
#include "../services/ClienteService.h"
#include "../services/CaixaService.h"

class Controller {
private:
    ProdutoService* produtoService;
    CategoriaService* categoriaService;
    ClienteService* clienteService;
    CaixaService* caixaService;

    View view;
    CatalogoView catalogoView;
    CategoriaView categoriaView;
    ClienteView clienteView;
    CaixaView caixaView;

    void runAdmin();
    void runCatalogo();
    void runCategorias();
    void runClientes();
    void runCaixas();
    void runCaixa(int idCaixa);

public:
    Controller(ProdutoService* produtoService, CategoriaService* categoriaService, ClienteService* clienteService, CaixaService* caixaService);
    void run();
    void adicionarProduto();
};
