#pragma once
#include "../view/MainMenuView.h"
#include "../view/AdminView.h"
#include "../view/CatalogoView.h"
#include "../view/CategoriaView.h"
#include "../view/CaixaView.h"
#include "../controller/CatalogoController.h"
#include "../controller/CategoriaController.h"

class Controller {
private:
    CatalogoController& catalogoController;
    CategoriaController& categoriaController;

    MainMenuView mainMenuView;
    AdminView adminView;
    CatalogoView catalogoView;
    CategoriaView categoriaView;
    CaixaView caixaView;

    void runAdmin();
    void runCaixa(int idCaixa);

public:
    Controller(CatalogoController& catalogoController, CategoriaController& categoriaController);
    void run();
};
