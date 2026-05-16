#pragma once
#include <string>

class Produto {
private:
    int id;
    std::string nome;
    double preco_base;
    int stock;
    int id_categoria;

public:
    Produto(int id, std::string nome, double preco_base, int stock, int id_categoria);

    int getId() const;
    std::string getNome() const;
    double getPrecoBase() const;
    int getStock() const;
    int getIdCategoria() const;
    
    void setNome(std::string novoNome);
    void setPrecoBase(double novoPreco);
    void addStock(int quantidade);
    void removerStock(int quantidade);
};
