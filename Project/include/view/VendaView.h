#pragma once
#include <string>
#include <vector>
#include "../dto/VendaDTO.h"
 
class VendaView {
public:
    VendaView();
    int mostrarMenuVenda();
    void printRecibo(const VendaDTO& venda);
    void printItensVendaAtual(const VendaDTO& venda);
    int getMetodoPagamento();
    void printListaVendas(const std::vector<VendaDTO>& vendas);
};