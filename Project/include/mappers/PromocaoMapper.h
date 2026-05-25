#pragma once
#include "../model/Promocao.h"
#include "../dto/PromocaoDTO.h"

class PromocaoMapper {
public:
    static PromocaoDTO toDTO(Promocao& p);
};
