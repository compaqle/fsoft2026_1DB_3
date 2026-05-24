#pragma once
#include "../model/Caixa.h"
#include "../dto/CaixaDTO.h"

class CaixaMapper {
public:
    static CaixaDTO toDTO(Caixa& c);
};
