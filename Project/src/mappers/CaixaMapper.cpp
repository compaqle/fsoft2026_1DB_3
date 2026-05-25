#include "../../include/mappers/CaixaMapper.h"

CaixaDTO CaixaMapper::toDTO(Caixa& c) {
    CaixaDTO dto;
    dto.id = c.getId();
    dto.nome = c.getNome();
    dto.totalFaturado = c.getTotalFaturado();
    return dto;
}