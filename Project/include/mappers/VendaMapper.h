#pragma once
#include "../model/Venda.h"
#include "../dto/VendaDTO.h"

class VendaMapper {
public:
    static VendaDTO toDTO(Venda& v);
};
