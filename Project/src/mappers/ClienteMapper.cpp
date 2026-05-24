#include "../../include/mappers/ClienteMapper.h"

ClienteDTO ClienteMapper::toDTO(Cliente& c) {
    ClienteDTO dto;
    dto.nif = std::to_string(c.getNif());
    dto.nome = c.getNome();
    dto.pontos = c.getSaldoPontos();
    return dto;
}
