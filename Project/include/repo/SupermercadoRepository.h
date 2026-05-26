#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../model/Categoria.h"
#include "../model/Cliente.h"
#include "../model/Caixa.h"
#include "../model/Venda.h"
#include "../model/Promocao.h"

class SupermercadoRepository {
private:
    static SupermercadoRepository* instance;

    std::vector<Produto*> produtos;
    std::vector<Categoria*> categorias;
    std::vector<Cliente*> clientes;
    std::vector<Caixa*> caixas;
    std::vector<Venda*> vendas;
    std::vector<Promocao*> promocoes;

    SupermercadoRepository();
    ~SupermercadoRepository();

    void carregarProdutos();
    void carregarCategorias();
    void carregarClientes();
    void carregarCaixas();
    void carregarVendas();
    void carregarPromocoes();

public:
    static SupermercadoRepository& getInstance();

    std::vector<Produto*>& getProdutos();
    void guardarProdutos();

    std::vector<Categoria*>& getCategorias();
    void guardarCategorias();
    
    std::vector<Cliente*>& getClientes();
    void guardarClientes();

    std::vector<Caixa*>& getCaixas();
    void guardarCaixas();

    std::vector<Venda*>& getVendas();
    void guardarVendas();

    std::vector<Promocao*>& getPromocoes();
    void guardarPromocoes();
};
