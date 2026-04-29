#pragma once
#include <vector>
#include "Produto.h"

class Venda {
private:
    int id;
    int nif_cliente;
    // No futuro terá uma lista de produtos
public:
    Venda(int id, int nif_cliente);
};
