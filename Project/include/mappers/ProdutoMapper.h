#pragma once
#include "../model/Produto.h"
#include "../dto/ProdutoDTO.h"

class ProdutoMapper {
public:
    static ProdutoDTO toDTO(Produto& p);
};
