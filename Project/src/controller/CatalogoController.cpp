#include "../../include/controller/CatalogoController.h"
#include "../../include/repo/SupermercadoRepository.h"

CatalogoController::CatalogoController() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i].getId() >= proximoId) {
            proximoId = produtos[i].getId() + 1;
        }
    }
}

void CatalogoController::criarProduto(std::string nome, double preco_base, int stock, int id_categoria) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Produto p(proximoId, nome, preco_base, stock, id_categoria);
    repo.getProdutos().push_back(p);
    proximoId++;
    repo.guardarProdutos();
}

void CatalogoController::removerProduto(int id) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i].getId() == id) {
            produtos.erase(produtos.begin() + i);
            repo.guardarProdutos();
            return;
        }
    }
}

std::vector<Produto>& CatalogoController::getProdutos() {
    return SupermercadoRepository::getInstance().getProdutos();
}
