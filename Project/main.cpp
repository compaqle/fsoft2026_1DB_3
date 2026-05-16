#include "include/controller/Controller.h"
#include "include/services/ProdutoService.h"
#include "include/services/CategoriaService.h"

int main() {
    ProdutoService produtoService;
    CategoriaService categoriaService;

    Controller controller(&produtoService, &categoriaService);
    controller.run();
    return 0;
}
