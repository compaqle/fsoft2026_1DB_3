#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../model/Categoria.h"

class SupermercadoRepository {
private:
    static SupermercadoRepository* instance;

    std::vector<Produto*> produtos;
    std::vector<Categoria*> categorias;

    SupermercadoRepository();
    ~SupermercadoRepository();

    void carregarProdutos();
    void carregarCategorias();

public:
    static SupermercadoRepository& getInstance();

    std::vector<Produto*>& getProdutos();
    void guardarProdutos();

    std::vector<Categoria*>& getCategorias();
    void guardarCategorias();
};
