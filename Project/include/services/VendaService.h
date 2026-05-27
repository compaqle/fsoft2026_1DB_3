#pragma once
#include <vector>
#include <string>


class Venda;
class Cliente;
class Produto;
class Caixa;
class SupermercadoRepository;

class VendaService {
private:
    SupermercadoRepository& repo;

public:

    VendaService(SupermercadoRepository& repo);


    Venda* abrirVenda(Caixa* caixa, Cliente* cliente);


    void adicionarItem(Venda* venda, int idProduto, int quantidade);


    void fecharVenda(Venda* venda, Caixa* caixa, const std::string& metodoPagamento);


    double consultarPreco(int idProduto) const;


    Venda* getUltimaVenda() const;

    const std::vector<Venda>& getVendas() const;

private:

    double calcularPrecoComIva(Produto* produto) const;
    void verificarStock(Produto* produto, int quantidade) const;
};