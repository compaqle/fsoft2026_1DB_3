#include "include/controller/Controller.h"
#include "include/services/ProdutoService.h"
#include "include/services/CategoriaService.h"
#include "include/services/ClienteService.h"
#include "include/services/CaixaService.h"

int main() {
    ProdutoService produtoService;
    CategoriaService categoriaService;
    ClienteService clienteService;
    CaixaService caixaService;

    Controller controller(&produtoService, &categoriaService, &clienteService, &caixaService);
    controller.run();
    return 0;
}
