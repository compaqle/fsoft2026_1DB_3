#pragma once
#include <vector>
#include <string>
#include "../../include/model/Produto.h"

class CatalogoView {
public:
    CatalogoView();

    int mostrarMenuCatalogo();
    void getDadosCriarProduto(std::string& nome, double& preco, int& stock, int& id_categoria);
    int getIdProduto();
    void printListaProdutos(std::vector<Produto>& lista);
    void printMensagem(const std::string& msg);
};
