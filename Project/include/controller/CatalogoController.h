#pragma once
#include <vector>
#include <string>
#include "../../include/model/Produto.h"

class CatalogoController {
private:
    std::vector<Produto> produtos;
    int proximoId;
    std::string caminhoFicheiro;

    void carregarFicheiro();
    void guardarEmFicheiro();

public:
    CatalogoController();
    void criarProduto(std::string nome, double preco_base, int stock, int id_categoria);
    void removerProduto(int id);
    std::vector<Produto>& getProdutos();
};
