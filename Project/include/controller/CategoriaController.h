#pragma once
#include <vector>
#include <string>
#include "../../include/model/Categoria.h"

class CategoriaController {
private:
    std::vector<Categoria> categorias;
    int proximoId;
    std::string caminhoFicheiro;

    void carregarFicheiro();
    void guardarEmFicheiro();

public:
    CategoriaController();
    void criarCategoria(std::string nome, double taxa_iva);
    std::vector<Categoria>& getCategorias();
};