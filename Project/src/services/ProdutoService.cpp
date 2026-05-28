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
    if (nome.empty()) {
        throw InvalidDataException("Produto: nome = (vazio)");
    }
    if (preco_base < 0) {
        throw InvalidDataException("Produto: preco = " + std::to_string(preco_base));
    }
    if (stock < 0) {
        throw InvalidDataException("Produto: stock = " + std::to_string(stock));
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* categoriaPointer = NULL;
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() == id_categoria) {
            categoriaPointer = categorias[i];
            break;
        }
    }
    
    if (categoriaPointer == NULL) {
        throw InvalidDataException("Produto: categoria = " + std::to_string(id_categoria) + " (nao encontrada)");
    }

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
        if (novo_nome.empty()) {
            throw InvalidDataException("Produto: nome = (vazio)");
        }
        produtoParaEditar->setNome(novo_nome);
    }
    
    if (novo_preco != -1.0) {
        if (novo_preco < 0) {
            throw InvalidDataException("Produto: preco = " + std::to_string(novo_preco));
        }
        produtoParaEditar->setPrecoBase(novo_preco);
    }
    
    if (novo_stock != -1) {
        if (novo_stock < 0) {
            throw InvalidDataException("Produto: stock = " + std::to_string(novo_stock));
        }
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
        
        if (categoriaPointer == NULL) {
            throw InvalidDataException("Produto: categoria = " + std::to_string(id_nova_categoria) + " (nao encontrada)");
        }
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
    if (produtos.empty()) {
        throw NoDataException("Produtos: (vazio)");
    }
    std::vector<ProdutoDTO> dtos;
    for (size_t i = 0; i < produtos.size(); i++) {
        dtos.push_back(ProdutoMapper::toDTO(*produtos[i]));
    }
    return dtos;
}
