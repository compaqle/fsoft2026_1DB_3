#pragma once
#include <vector>
#include <string>
#include "../../include/model/Produto.h"

class CatalogoController {
private:
    int proximoId;

public:
    CatalogoController();
    void criarProduto(std::string nome, double preco_base, int stock, int id_categoria);
    void removerProduto(int id);
    std::vector<Produto>& getProdutos();
};
