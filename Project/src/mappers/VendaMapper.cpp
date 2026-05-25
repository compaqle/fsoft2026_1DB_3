#include "../../include/mappers/VendaMapper.h"
#include "../../include/model/Cliente.h"
#include "../../include/model/ItemVenda.h"

VendaDTO VendaMapper::toDTO(Venda& v) {
    VendaDTO dto;
    dto.id = v.getId();
    dto.dataHora = v.getDataHora();
    dto.total = v.getTotal();
    dto.metodoPagamento = v.getMetodoPagamento();

    if (v.getCliente() != NULL) {
        dto.nifCliente = std::to_string(v.getCliente()->getNif());
        dto.nomeCliente = v.getCliente()->getNome();
    } else {
        dto.nifCliente = "";
        dto.nomeCliente = "Sem cliente";
    }

    std::vector<ItemVenda> itens = v.getVendas();
    for (size_t i = 0; i < itens.size(); i++) {
        ItemVendaDTO itemDto;
        itemDto.nomeProduto = itens[i].getProduto()->getNome();
        itemDto.quantidade = itens[i].getQuantidade();
        itemDto.precoUnitario = itens[i].getPrecoUnitario();
        itemDto.subTotal = itens[i].getSubtotal();
        dto.itens.push_back(itemDto);
    }

    return dto;
}