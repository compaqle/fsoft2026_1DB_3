#include "../../include/model/Produto.h"

namespace model {

// CONSTRUTOR
Produto::Produto(int id, std::string nome, double preco_base, int stock, int id_categoria) {
    this->id = id;
    this->nome = nome;
    this->preco_base = preco_base;
    this->stock = stock;
    this->id_categoria = id_categoria;
}

// GETTERS
int Produto::getId() { return id; }
std::string Produto::getNome() { return nome; }
double Produto::getPrecoBase() { return preco_base; }
int Produto::getStock() { return stock; }
int Produto::getIdCategoria() { return id_categoria; }

// SETTERS
void Produto::setNome(std::string novoNome) { this->nome = novoNome; }
void Produto::setPrecoBase(double novoPreco) { this->preco_base = novoPreco; }

// GESTÃO DE STOCK
void Produto::addStock(int quantidade) {
    this->stock += quantidade;
}

void Produto::removerStock(int quantidade) {
    if (this->stock >= quantidade) {
        this->stock -= quantidade;
    }
}

} // namespace model
