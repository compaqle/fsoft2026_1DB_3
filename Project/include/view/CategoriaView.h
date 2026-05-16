#pragma once
#include <vector>
#include <string>
#include "../dto/CategoriaDTO.h"

class CategoriaView {
public:
    CategoriaView();

    int mostrarMenuCategorias();
    void getDadosCriarCategoria(std::string& nome, double& taxa_iva);
    void printListaCategorias(const std::vector<CategoriaDTO>& lista);
    void printMensagem(const std::string& msg);
};
