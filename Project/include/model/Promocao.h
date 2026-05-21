#pragma once
#include <string>

class Produto;
class Categoria;

class Promocao {
private:
    int id;
    double percentagem;
    std::string data_inicio;
    std::string data_final;
    Produto* produto;
    Categoria* categoria;
public:
    Promocao(int id, double percentagem , const std::string& data_inicio , const std::string& data_final, Produto* produto, Categoria* categoria);
    int getId() const;
    int getPercentagem() const;
    std::string getData_Inicio() const;
    std::string getData_Final() const;
    Produto* getProduto() const;
    Categoria* getCategoria() const;

    void setProduto(Produto* produto);
    void setCategoria(Categoria* categoria);
    void setPercentagem(double percentagem);
    void setData_inicio(std::string data_inicio);
    void setData_final(std::string data_final);




};