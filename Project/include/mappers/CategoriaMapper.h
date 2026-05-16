#pragma once
#include "../model/Categoria.h"
#include "../dto/CategoriaDTO.h"

class CategoriaMapper {
public:
    static CategoriaDTO toDTO(Categoria& c);
};
