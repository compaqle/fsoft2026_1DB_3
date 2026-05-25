#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../model/Categoria.h"
#include "../model/Cliente.h"
#include "../model/Venda.h"
#include "../model/promoçao.h"

class SupermercadoRepository {
private:
    static SupermercadoRepository* instance;

    std::vector<Produto> produtos;
    std::vector<Categoria> categorias;
    std::vector<Cliente> cliente;
    std::vector<Venda> vendas;
    std::vector<Promocao> promocoes;


    SupermercadoRepository();

    void carregarProdutos();
    void carregarCategorias();
    void carregarClientes();
    void carregarVendas();
    void carregarPromocoes();

public:
    static SupermercadoRepository& getInstance();

    std::vector<Produto>& getProdutos();
    void guardarProdutos();

    std::vector<Categoria>& getCategorias();
    void guardarCategorias();

    std::vector<Cliente>& getClientes();
    void guardarClientes();

    std::vector<Venda>& getVendas();
    void guardarVendas();

    std::vector<Promocao>& getPromocoes();
    void guardarPromocoes();

};
