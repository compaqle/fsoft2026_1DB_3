#pragma once
#include <vector>
#include <string>
#include "../model/Produto.h"
#include "../model/Categoria.h"
#include "../model/Cliente.h"
#include "../model/Venda.h"
#include "../model/Promocao.h"
#include "../model/Caixa.h"
#include "../model/Venda.h"
#include "../model/Promocao.h"

class SupermercadoRepository {
private:
    static SupermercadoRepository* instance;


    std::vector<Produto> produtos;
    std::vector<Categoria> categorias;
    std::vector<Cliente> cliente;
    std::vector<Venda> vendas;
    std::vector<Promocao> promocoes;

    std::vector<Produto*> produtos_ptr;
    std::vector<Categoria*> categorias_ptr;
    std::vector<Cliente*> clientes;
    std::vector<Caixa*> caixas;
    std::vector<Venda*> vendas_ptr;
    std::vector<Promocao*> promocoes_ptr;

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
    
    std::vector<Cliente>& getClientes();
    void guardarClientes();

    std::vector<Venda>& getVendas();
    void guardarVendas();

    std::vector<Promocao>& getPromocoes();
    void guardarPromocoes();

    std::vector<Cliente*>& getClientes_ptr();
    void guardarClientes_ptr();

    std::vector<Caixa*>& getCaixas();
    void guardarCaixas();

    std::vector<Venda*>& getVendas_ptr();
    void guardarVendas_ptr();

    std::vector<Promocao*>& getPromocoes_ptr();
    void guardarPromocoes_ptr();
};
