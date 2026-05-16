#include "../../include/services/ProdutoService.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"

ProdutoService::ProdutoService() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i].getId() >= proximoId) {
            proximoId = produtos[i].getId() + 1;
        }
    }
}

void ProdutoService::criarProduto(std::string nome, double preco_base, int stock, int id_categoria) {
    if (nome.empty()) throw InvalidDataException("nome vazio");
    if (preco_base < 0) throw InvalidDataException("preco negativo");
    if (stock < 0) throw InvalidDataException("stock negativo");

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Produto p(proximoId, nome, preco_base, stock, id_categoria);
    repo.getProdutos().push_back(p);
    proximoId++;
    repo.guardarProdutos();
}

void ProdutoService::removerProduto(int id) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i].getId() == id) {
            produtos.erase(produtos.begin() + i);
            repo.guardarProdutos();
            return;
        }
    }
    throw NoDataException("Produto: " + std::to_string(id));
}

std::vector<Produto>& ProdutoService::getProdutos() {
    return SupermercadoRepository::getInstance().getProdutos();
}
