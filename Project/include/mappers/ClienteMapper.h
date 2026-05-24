#pragma once
#include "../model/Cliente.h"
#include "../dto/ClienteDTO.h"

class ClienteMapper {
public:
    static ClienteDTO toDTO(Cliente& c);
};