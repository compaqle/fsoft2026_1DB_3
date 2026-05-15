#pragma once
#include <vector>
#include <string>
#include "../../include/model/Categoria.h"

class CategoriaController {
private:
    int proximoId;

public:
    CategoriaController();
    void criarCategoria(std::string nome, double taxa_iva);
    std::vector<Categoria>& getCategorias();
};
