#include "../../include/services/ProdutoService.h"
#include "../../include/mappers/ProdutoMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"

ProdutoService::ProdutoService() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() >= proximoId) {
            proximoId = produtos[i]->getId() + 1;
        }
    }
}

void ProdutoService::criarProduto(std::string nome, double preco_base, int stock, int id_categoria) {
    if (nome.empty()) throw InvalidDataException("nome vazio");
    if (preco_base < 0) throw InvalidDataException("preco negativo");
    if (stock < 0) throw InvalidDataException("stock negativo");

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* categoriaPointer = NULL;
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() == id_categoria) {
            categoriaPointer = categorias[i];
            break;
        }
    }
    if (categoriaPointer == NULL) throw InvalidDataException("categoria nao encontrada");

    Produto* p = new Produto(proximoId, nome, preco_base, stock, categoriaPointer);
    repo.getProdutos().push_back(p);
    proximoId++;
    repo.guardarProdutos();
}

void ProdutoService::removerProduto(int id) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id) {
            Produto* p = produtos[i];
            produtos.erase(produtos.begin() + i);
            delete p;
            repo.guardarProdutos();
            return;
        }
    }
    throw NoDataException("Produto: " + std::to_string(id));
}

std::vector<ProdutoDTO> ProdutoService::getProdutos() {
    std::vector<Produto*>& produtos = SupermercadoRepository::getInstance().getProdutos();
    std::vector<ProdutoDTO> dtos;
    for (size_t i = 0; i < produtos.size(); i++) {
        dtos.push_back(ProdutoMapper::toDTO(*produtos[i]));
    }
    return dtos;
}
