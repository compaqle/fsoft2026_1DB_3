#include "../../include/model/Produto.h"
#include "../../include/model/Categoria.h"
#include "../../include/exceptions/InvalidDataException.h"

Produto::Produto(int id, std::string nome, double preco_base, int stock, Categoria* categoria) {
    this->setId(id);
    this->setNome(nome);
    this->setPrecoBase(preco_base);
    this->setStock(stock);
    this->setCategoria(categoria);
}

int Produto::getId() const { return id; }
std::string Produto::getNome() const { return nome; }
double Produto::getPrecoBase() const { return preco_base; }
int Produto::getStock() const { return stock; }
Categoria* Produto::getCategoria() const { return categoria; }

void Produto::setNome(std::string novoNome) {
    if (isNomeValid(novoNome)) {
        this->nome = novoNome;
    } else {
        throw InvalidDataException("Produto: nome = " + novoNome);
    }
}

void Produto::setPrecoBase(double novoPreco) {
    if (isPrecoValid(novoPreco)) {
        this->preco_base = novoPreco;
    } else {
        throw InvalidDataException("Produto: preco_base = " + std::to_string(novoPreco));
    }
}

void Produto::setStock(int novoStock) {
    if (isStockValid(novoStock)) {
        this->stock = novoStock;
    } else {
        throw InvalidDataException("Produto: stock = " + std::to_string(novoStock));
    }
}

void Produto::setCategoria(Categoria* novaCategoria) {
    if (isCategoriaValid(novaCategoria)) {
        this->categoria = novaCategoria;
    } else {
        throw InvalidDataException("Produto: categoria = NULL");
    }
}

void Produto::setId(int id) {
    if (id > 0) {
        this->id = id;
    } else {
        throw InvalidDataException("Produto: id = " + std::to_string(id));
    }
}

bool Produto::isNomeValid(const std::string& nome) {
    return !nome.empty();
}

bool Produto::isPrecoValid(double preco) {
    return preco >= 0;
}

bool Produto::isStockValid(int stock) {
    return stock >= 0;
}

bool Produto::isCategoriaValid(Categoria* cat) {
    return cat != nullptr;
}

void Produto::addStock(int quantidade) {
    this->setStock(this->stock + quantidade);
}

void Produto::removerStock(int quantidade) {
    this->setStock(this->stock - quantidade);
}
