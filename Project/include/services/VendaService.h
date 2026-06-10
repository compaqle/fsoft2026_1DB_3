#pragma once
#include <vector>
#include <string>
#include "../dto/VendaDTO.h"
#include "../repo/SupermercadoRepository.h"

class VendaService {
private:
    int proximoId;
    // Venda em curso (NULL se nao ha venda ativa)
    int idVendaAtiva;
    bool vendaEmCurso;

    double calcularMelhorDesconto(int id_produto) const;

public:
    VendaService();

    // Ciclo de vida da venda
    void iniciarVenda(int nif_cliente); // nif_cliente = 0 se sem cliente
    void adicionarItem(int id_produto, int quantidade);
    void removerItem(int id_produto);
    double calcularTotal() const;
    VendaDTO concluirVenda(const std::string& metodo_pagamento, int id_caixa);
    void cancelarVenda();

    bool temVendaAtiva() const;
    VendaDTO getVendaAtiva() const;

    // Historico
    std::vector<VendaDTO> getVendas() const;
    std::vector<VendaDTO> getVendasDoCaixa(int id_caixa) const;
    VendaDTO getVendaPorId(int id) const;

    // Consulta de preco com promoções
    double consultarPreco(int id_produto) const;
};
