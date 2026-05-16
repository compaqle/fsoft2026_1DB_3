#include "../../include/mappers/CategoriaMapper.h"

CategoriaDTO CategoriaMapper::toDTO(Categoria& c) {
    CategoriaDTO dto;
    dto.id = c.getId();
    dto.nome = c.getNome();
    dto.taxa_iva = c.getTaxaIva();
    return dto;
}
