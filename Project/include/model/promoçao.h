#pragma once
#include <string>

class Promocao {
private:
    int id;
    double percentagem;
    std::string data_inicio;
    std::string data_final;
    int id_produto;
    int id_categoria;
public:
    Promocao(int id, double percentagem , const std::string& data_inicio , const std::string& data_final, int id_produto, int id_categoria);
    int getId() const;
    int getPercentagem() const;
    std::string getData_Inicio() const;
    std::string getData_Final() const;
    int getIdProduto() const;
    int getIdCategoria() const;

    void setIdProduto(int id_produto);
    void setIdCategoria(int id_categoria);
    void setPercentagem(double percentagem);
    void setData_inicio(std::string data_inicio);
    void setData_final(std::string data_final);




};