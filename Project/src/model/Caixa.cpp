#include "../../include/model/Caixa.h"
#include "../../include/model/Venda.h"
#include "../../include/exceptions/InvalidDataException.h"

Caixa::Caixa(int id, const std::string& nome) : Utilizador(id, nome) {
    this->total_faturado = 0.0;
    vendaAtual = nullptr;
}

double Caixa::getTotalFaturado() const { 
    return total_faturado;
}

void Caixa::adicionarFaturacao(double valor) { 
    total_faturado += valor;
}

Venda* Caixa::getVendaAtual() const {
    return vendaAtual;
}

void Caixa::setVendaAtual(Venda* venda) {
    if (venda != nullptr) {
        if (this->vendaAtual != nullptr) {
            throw InvalidDataException("A caixa já tem uma venda em progresso!");
        }
        this->vendaAtual = venda;
    } else {
        throw InvalidDataException("Venda inválida (nullptr).");
    }
}

void Caixa::fecharVendaAtual(Venda* venda) {
    if (this->vendaAtual == nullptr) {
        throw InvalidDataException("Não há nenhuma venda em progresso para fechar.");
    }
    if (this->vendaAtual != venda) {
        throw InvalidDataException("A venda fornecida não corresponde à venda atual da caixa.");
    }
    this->vendaAtual = nullptr;
}
