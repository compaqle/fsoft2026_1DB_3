#include "../../include/mappers/ProdutoMapper.h"

ProdutoDTO ProdutoMapper::toDTO(Produto& p) {
    ProdutoDTO dto;
    dto.id = p.getId();
    dto.nome = p.getNome();
    dto.preco = p.getPrecoBase();
    dto.stock = p.getStock();
    return dto;
}
