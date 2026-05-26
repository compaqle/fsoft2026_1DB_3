#include "../../include/mappers/PromocaoMapper.h"
#include "../../include/model/Produto.h"
#include "../../include/model/Categoria.h"

PromocaoDTO PromocaoMapper::toDTO(Promocao& p) {
    PromocaoDTO dto;
    dto.id = p.getId();
    dto.percentagem = p.getPercentagem();
    dto.dataInicio = p.getData_Inicio();
    dto.dataFim = p.getData_Final();
    dto.nomeProduto = p.getProduto() ? p.getProduto()->getNome() : "";
    dto.nomeCategoria = p.getCategoria() ? p.getCategoria()->getNome() : "";
    return dto;
}
