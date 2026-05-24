#include "../../include/model/Promocao.h"

Promocao::Promocao(int id, double percentagem, const std::string& data_inicio, const std::string& data_final, Produto* produto, Categoria* categoria) {
    this->id = id;
    this->percentagem = percentagem;
    this->data_inicio = data_inicio;
    this->data_final = data_final;
    this->produto = produto;
    this->categoria = categoria;
}

int Promocao::getId() const { return id; }
double Promocao::getPercentagem() const { return percentagem; }
std::string Promocao::getData_Inicio() const { return data_inicio; }
std::string Promocao::getData_Final() const { return data_final; }
Produto* Promocao::getProduto() const { return produto; }
Categoria* Promocao::getCategoria() const { return categoria; }

void Promocao::setProduto(Produto* produto) { this->produto = produto; }
void Promocao::setCategoria(Categoria* categoria) { this->categoria = categoria; }
void Promocao::setPercentagem(double percentagem) { this->percentagem = percentagem; }
void Promocao::setData_inicio(std::string data_inicio) { this->data_inicio = data_inicio; }
void Promocao::setData_final(std::string data_final) { this->data_final = data_final; }