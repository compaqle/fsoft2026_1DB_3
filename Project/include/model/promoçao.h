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
    int getid() const;
    int getpercentagem() const;
    std::string getdata_inicio() const;
    std::string getdata_final() const;
    int getIdProduto() const;
    int getIdCategoria() const;

    void setIdProduto(int id_produto);
    void setIdCategoria(int id_categoria);
    void setpercentagem(double percentagem);
    void setdata_inicio(std::string data_inicio);
    void setdata_final(std::string data_final);




};