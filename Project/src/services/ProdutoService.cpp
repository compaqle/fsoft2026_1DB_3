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
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* categoriaPointer = NULL;
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() == id_categoria) {
            categoriaPointer = categorias[i];
            break;
        }
    }

    // O construtor de Produto trata as validacoes de nome, preco, stock e categoria != NULL
    Produto* p = new Produto(proximoId, nome, preco_base, stock, categoriaPointer);
    repo.getProdutos().push_back(p);
    proximoId++;
    repo.guardarProdutos();
}

void ProdutoService::editarProduto(int id, std::string novo_nome, double novo_preco, int novo_stock, int id_nova_categoria) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto*>& produtos = repo.getProdutos();
    
    Produto* produtoParaEditar = NULL;
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id) {
            produtoParaEditar = produtos[i];
            break;
        }
    }
    
    if (produtoParaEditar == NULL) {
        throw NoDataException("Produto: id = " + std::to_string(id) + " (nao encontrado)");
    }

    if (novo_nome != "-1") {
        produtoParaEditar->setNome(novo_nome);
    }
    
    if (novo_preco != -1.0) {
        produtoParaEditar->setPrecoBase(novo_preco);
    }
    
    if (novo_stock != -1) {
        produtoParaEditar->setStock(novo_stock);
    }
    
    if (id_nova_categoria != -1) {
        Categoria* categoriaPointer = NULL;
        std::vector<Categoria*>& categorias = repo.getCategorias();
        for (size_t i = 0; i < categorias.size(); i++) {
            if (categorias[i]->getId() == id_nova_categoria) {
                categoriaPointer = categorias[i];
                break;
            }
        }
        
        // O setCategoria trata a validacao de ponteiro nulo
        produtoParaEditar->setCategoria(categoriaPointer);
    }
    
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
    throw NoDataException("Produto: id = " + std::to_string(id) + " (nao encontrado)");
}

std::vector<ProdutoDTO> ProdutoService::getProdutos() {
    std::vector<Produto*>& produtos = SupermercadoRepository::getInstance().getProdutos();
    std::vector<ProdutoDTO> dtos;
    for (size_t i = 0; i < produtos.size(); i++) {
        dtos.push_back(ProdutoMapper::toDTO(*produtos[i]));
    }
    return dtos;
}
