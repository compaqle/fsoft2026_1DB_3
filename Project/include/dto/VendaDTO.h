#pragma once
#include <string>
#include <vector>

struct ItemVendaDTO {
    std::string nomeProduto;
    int quantidade;
    double precoUnitario;
    double subTotal;
};
struct VendaDTO {
    int id;
    std::string dataHora;
    double total;
    std::string metodoPagamento;
    std::string nifCliente;
    std::string nomeCliente;
    std::vector<ItemVendaDTO> itens;
};