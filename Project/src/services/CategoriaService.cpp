#include "../../include/services/CategoriaService.h"

CategoriaService::CategoriaService() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Categoria>& categorias = repo.getCategorias();
    for (int i = 0; i < (int)categorias.size(); i++) {
        if (categorias[i].getId() >= proximoId) {
            proximoId = categorias[i].getId() + 1;
        }
    }
}

void CategoriaService::criarCategoria(std::string nome, double taxa_iva) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria c(proximoId, nome, taxa_iva);
    repo.getCategorias().push_back(c);
    proximoId++;
    repo.guardarCategorias();
}

std::vector<Categoria>& CategoriaService::getCategorias() {
    return SupermercadoRepository::getInstance().getCategorias();
}
