#pragma once
#include <vector>
#include <string>
#include"../repo/SupermercadoRepository.h"
#include"../model/Cliente.h"

class ClienteService{
private:
SupermercadoRepository& repo;
public:
    ClienteService(SupermercadoRepository& repo);

    Cliente* getClientePorNif(int nif)const;
    int consultarPontos(int nif)const;
    void acumularPontos(Cliente* cliente,double TotalVenda);
    void gastarPontos(Cliente* cliente,int quantidade);
    void criarCliente(int nif,const std::string& nome);
    const std::vector<Cliente*>& getClientes()const;
};
