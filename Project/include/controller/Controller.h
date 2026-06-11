#pragma once
#include "../view/View.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../view/ClienteView.h"
#include "../view/CaixaView.h"
#include "../view/VendaView.h"
#include "../view/PromocaoView.h"
#include "../services/ProdutoService.h"
#include "../services/CategoriaService.h"
#include "../services/ClienteService.h"
#include "../services/CaixaService.h"
#include "../services/VendaService.h"
#include "../services/PromocaoService.h"

class Controller {
private:
    ProdutoService* produtoService;
    CategoriaService* categoriaService;
    ClienteService* clienteService;
    CaixaService* caixaService;
    VendaService* vendaService;
    PromocaoService* promocaoService;

    View view;
    CatalogoView catalogoView;
    CategoriaView categoriaView;
    ClienteView clienteView;
    CaixaView caixaView;
    VendaView vendaView;
    PromocaoView promocaoView;

    void runAdmin();
    void runCatalogo();
    void runCategorias();
    void runClientes();
    void runCaixas();
    void runPromocoes();
    void runEstatisticas();
    void runCaixa(int idCaixa);
    void runRealizarVenda(int idCaixa);

public:
    Controller(ProdutoService* produtoService, CategoriaService* categoriaService, ClienteService* clienteService, CaixaService* caixaService, VendaService* vendaService, PromocaoService* promocaoService);
    void run();
};
