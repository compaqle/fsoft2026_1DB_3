#include "../../include/model/Produto.h"

Produto::Produto(int id, std::string nome, double preco_base, int stock, int id_categoria) {
    this->id = id;
    this->nome = nome;
    this->preco_base = preco_base;
    this->stock = stock;
    this->id_categoria = id_categoria;
}

int Produto::getId() const { return id; }
std::string Produto::getNome() const { return nome; }
double Produto::getPrecoBase() const { return preco_base; }
int Produto::getStock() const { return stock; }
int Produto::getIdCategoria() const { return id_categoria; }

void Produto::setNome(std::string novoNome) { this->nome = novoNome; }
void Produto::setPrecoBase(double novoPreco) { this->preco_base = novoPreco; }

void Produto::addStock(int quantidade) {
    this->stock += quantidade;
}

void Produto::removerStock(int quantidade) {
    if (this->stock >= quantidade) {
        this->stock -= quantidade;
    }
}
