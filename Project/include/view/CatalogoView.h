#pragma once
#include <vector>
#include <string>
#include "../dto/ProdutoDTO.h"

class CatalogoView {
public:
    CatalogoView();

    int mostrarMenuCatalogo();
    void getDadosCriarProduto(std::string& nome, double& preco, int& stock, int& id_categoria);
    int getIdProduto();
    int getIdProdutoEditar();
    void printListaProdutos(const std::vector<ProdutoDTO>& lista);
};
