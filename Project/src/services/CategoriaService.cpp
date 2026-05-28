#include "../../include/services/CategoriaService.h"
#include "../../include/mappers/CategoriaMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"

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
    if (nome.empty()) {
        throw InvalidDataException("Categoria: nome = (vazio)");
    }
    if (taxa_iva < 0) {
        throw InvalidDataException("Categoria: taxa_iva = " + std::to_string(taxa_iva));
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* c = new Categoria(proximoId, nome, taxa_iva);
    repo.getCategorias().push_back(c);
    proximoId++;
    repo.guardarCategorias();
}

void CategoriaService::editarCategoria(int id, std::string novo_nome, double nova_taxa) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Categoria*>& categorias = repo.getCategorias();
    
    Categoria* catParaEditar = NULL;
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() == id) {
            catParaEditar = categorias[i];
            break;
        }
    }
    
    if (catParaEditar == NULL) {
        throw NoDataException("Categoria: id = " + std::to_string(id) + " (nao encontrada)");
    }

    if (novo_nome != "-1") {
        if (novo_nome.empty()) {
            throw InvalidDataException("Categoria: nome = (vazio)");
        }
        catParaEditar->setNome(novo_nome);
    }
    
    if (nova_taxa != -1.0) {
        if (nova_taxa < 0) {
            throw InvalidDataException("Categoria: taxa_iva = " + std::to_string(nova_taxa));
        }
        catParaEditar->setTaxaIva(nova_taxa);
    }
    
    repo.guardarCategorias();
}

std::vector<CategoriaDTO> CategoriaService::getCategorias() {
    std::vector<Categoria*>& categorias = SupermercadoRepository::getInstance().getCategorias();
    if (categorias.empty()) {
        throw NoDataException("Categorias: (vazio)");
    }
    std::vector<CategoriaDTO> dtos;
    for (size_t i = 0; i < categorias.size(); i++) {
        dtos.push_back(CategoriaMapper::toDTO(*categorias[i]));
    }
    return dtos;
}
