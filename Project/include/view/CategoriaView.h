#pragma once
#include <vector>
#include <string>
#include "../dto/CategoriaDTO.h"

class CategoriaView {
public:
    CategoriaView();

    int mostrarMenuCategorias();
    void getDadosCriarCategoria(std::string& nome, double& taxa_iva);
    int getIdCategoriaEditar();
    int getIdCategoria();
    void printListaCategorias(const std::vector<CategoriaDTO>& lista);
};
