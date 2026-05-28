#pragma once
#include <vector>
#include <string>
#include "../model/Categoria.h"
#include "../dto/CategoriaDTO.h"
#include "../repo/SupermercadoRepository.h"

class CategoriaService {
private:
    int proximoId;

public:
    CategoriaService();
    void criarCategoria(std::string nome, double taxa_iva);
    void editarCategoria(int id, std::string novo_nome, double nova_taxa);
    std::vector<CategoriaDTO> getCategorias();
};
