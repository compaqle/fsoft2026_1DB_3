#include "include/controller/Controller.h"
#include "include/services/ProdutoService.h"
#include "include/services/CategoriaService.h"
#include "include/services/ClienteService.h"
#include "include/services/CaixaService.h"
#include "include/services/VendaService.h"
#include "include/services/PromocaoService.h"

int main() {
    ProdutoService produtoService;
    CategoriaService categoriaService;
    ClienteService clienteService;
    CaixaService caixaService;
    VendaService vendaService;
    PromocaoService promocaoService;

    Controller controller(&produtoService, &categoriaService, &clienteService, &caixaService, &vendaService, &promocaoService);
    controller.run();
    return 0;
}
