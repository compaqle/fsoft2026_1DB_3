#include "include/controller/Controller.h"
#include "include/services/ProdutoService.h"
#include "include/services/CategoriaService.h"
#include "include/services/ClienteService.h"
#include "include/services/CaixaService.h"
#include "include/services/VendaService.h"

int main() {
    ProdutoService produtoService;
    CategoriaService categoriaService;
    ClienteService clienteService;
    CaixaService caixaService;
    VendaService vendaService;

    Controller controller(&produtoService, &categoriaService, &clienteService, &caixaService, &vendaService);
    controller.run();
    return 0;
}
