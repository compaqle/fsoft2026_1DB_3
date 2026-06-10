#include "../../include/view/VendaView.h"
#include "../../include/view/Utils.h"
#include <iostream>
#include <iomanip>

VendaView::VendaView() {}

int VendaView::mostrarMenuVenda() {
    std::cout << "\n--- Menu Venda ---" << std::endl;
    std::cout << "1. Adicionar produto" << std::endl;
    std::cout << "2. Remover produto" << std::endl;
    std::cout << "3. Ver itens da venda" << std::endl;
    std::cout << "4. Concluir venda" << std::endl;
    std::cout << "0. Cancelar venda" << std::endl;
    return Utils::lerInt("Opcao: ");
}

void VendaView::printRecibo(const VendaDTO& venda) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "               RECIBO                   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Venda #" << venda.id << "  |  " << venda.dataHora << std::endl;
    std::cout << "Cliente: " << venda.nomeCliente;
    if (!venda.nifCliente.empty() && venda.nifCliente != "0") {
        std::cout << " (NIF: " << venda.nifCliente << ")";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::left << std::setw(22) << "Produto"
              << std::right << std::setw(4) << "Qtd"
              << std::setw(9) << "Preco"
              << std::setw(10) << "Subtotal" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (size_t i = 0; i < venda.itens.size(); i++) {
        std::cout << std::left << std::setw(22) << venda.itens[i].nomeProduto
                  << std::right << std::setw(4) << venda.itens[i].quantidade
                  << std::setw(8) << std::fixed << std::setprecision(2) << venda.itens[i].precoUnitario << "E"
                  << std::setw(9) << std::fixed << std::setprecision(2) << venda.itens[i].subTotal << "E"
                  << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::right << std::setw(36) << "TOTAL: "
              << std::fixed << std::setprecision(2) << venda.total << "E" << std::endl;
    std::cout << "Pagamento: " << venda.metodoPagamento << std::endl;
    std::cout << "========================================" << std::endl;
}

void VendaView::printItensVendaAtual(const VendaDTO& venda) {
    std::cout << "\n--- Itens na venda em curso ---" << std::endl;
    if (venda.itens.empty()) {
        std::cout << "Nenhum item adicionado." << std::endl;
        return;
    }
    for (size_t i = 0; i < venda.itens.size(); i++) {
        std::cout << "  " << venda.itens[i].nomeProduto
                  << "  x" << venda.itens[i].quantidade
                  << "  @" << std::fixed << std::setprecision(2) << venda.itens[i].precoUnitario
                  << "E  = " << std::fixed << std::setprecision(2) << venda.itens[i].subTotal << "E"
                  << std::endl;
    }
    std::cout << "Total parcial: " << std::fixed << std::setprecision(2) << venda.total << "E" << std::endl;
}

int VendaView::getMetodoPagamento() {
    std::cout << "\n--- Metodo de Pagamento ---" << std::endl;
    std::cout << "1. Numerario" << std::endl;
    std::cout << "2. Cartao de Credito" << std::endl;
    std::cout << "3. Cartao de Debito" << std::endl;
    std::cout << "4. MB Way" << std::endl;
    return Utils::lerInt("Opcao: ");
}

void VendaView::printListaVendas(const std::vector<VendaDTO>& vendas) {
    std::cout << "\n--- Historico de Vendas ---" << std::endl;
    if (vendas.empty()) {
        std::cout << "Nenhuma venda registada." << std::endl;
        return;
    }
    for (size_t i = 0; i < vendas.size(); i++) {
        std::cout << "#" << vendas[i].id
                  << "  " << vendas[i].dataHora
                  << "  Cliente: " << vendas[i].nomeCliente
                  << "  Total: " << std::fixed << std::setprecision(2) << vendas[i].total << "E"
                  << "  Pagamento: " << vendas[i].metodoPagamento
                  << std::endl;
    }
}
