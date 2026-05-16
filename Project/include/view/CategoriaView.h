#pragma once
#include <vector>
#include <string>
#include "../../include/model/Categoria.h"

class CategoriaView {
public:
    CategoriaView();

    int mostrarMenuCategorias();
    void getDadosCriarCategoria(std::string& nome, double& taxa_iva);
    void printListaCategorias(std::vector<Categoria>& lista);
    void printMensagem(const std::string& msg);
};
