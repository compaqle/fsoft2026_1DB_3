#pragma once
#include <string>

class Categoria;

class Produto {
private:
    int id;
    std::string nome;
    double preco_base;
    int stock;
    Categoria* categoria;

public:
    Produto(int id, std::string nome, double preco_base, int stock, Categoria* categoria);

    int getId() const;
    std::string getNome() const;
    double getPrecoBase() const;
    int getStock() const;
    Categoria* getCategoria() const;
    
    void setNome(std::string novoNome);
    void setPrecoBase(double novoPreco);
    void addStock(int quantidade);
    void removerStock(int quantidade);
};
