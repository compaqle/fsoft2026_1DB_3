#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../dto/ProdutoDTO.h"
#include "../repo/SupermercadoRepository.h"

class ProdutoService {
private:
    int proximoId;

public:
    ProdutoService();
    void criarProduto(std::string nome, double preco_base, int stock, int id_categoria);
    void editarProduto(int id, std::string novo_nome, double novo_preco, int novo_stock, int id_nova_categoria);
    void removerProduto(int id);
    std::vector<ProdutoDTO> getProdutos();
};
