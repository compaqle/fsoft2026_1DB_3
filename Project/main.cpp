#include "include/controller/Controller.h"

int main() {
    CatalogoController catalogoController;
    CategoriaController categoriaController;

    Controller controller(catalogoController, categoriaController);
    controller.run();
    return 0;
}
