#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../repo/SupermercadoRepository.h"

class ProdutoService {
private:
    int proximoId;

public:
    ProdutoService();
    void criarProduto(std::string nome, double preco_base, int stock, int id_categoria);
    void removerProduto(int id);
    std::vector<Produto>& getProdutos();
};
