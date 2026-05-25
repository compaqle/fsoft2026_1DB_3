#include "../../include/services/CategoriaService.h"
#include "../../include/mappers/CategoriaMapper.h"
#include "../../include/exceptions/InvalidDataException.h"

CategoriaService::CategoriaService() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() >= proximoId) {
            proximoId = categorias[i]->getId() + 1;
        }
    }
}

void CategoriaService::criarCategoria(std::string nome, double taxa_iva) {
    if (nome.empty()) throw InvalidDataException("nome vazio");
    if (taxa_iva < 0) throw InvalidDataException("taxa de IVA negativa");

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* c = new Categoria(proximoId, nome, taxa_iva);
    repo.getCategorias().push_back(c);
    proximoId++;
    repo.guardarCategorias();
}

std::vector<CategoriaDTO> CategoriaService::getCategorias() {
    std::vector<Categoria*>& categorias = SupermercadoRepository::getInstance().getCategorias();
    std::vector<CategoriaDTO> dtos;
    for (size_t i = 0; i < categorias.size(); i++) {
        dtos.push_back(CategoriaMapper::toDTO(*categorias[i]));
    }
    return dtos;
}
