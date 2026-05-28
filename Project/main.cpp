#include "include/controller/Controller.h"
#include "include/services/ProdutoService.h"
#include "include/services/CategoriaService.h"
#include "include/services/ClienteService.h"

int main() {
    ProdutoService produtoService;
    CategoriaService categoriaService;
    ClienteService clienteService;

    Controller controller(&produtoService, &categoriaService, &clienteService);
    controller.run();
    return 0;
}
