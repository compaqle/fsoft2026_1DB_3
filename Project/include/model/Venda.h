#pragma once
#include <vector>
#include "Produto.h"

namespace model {

class Venda {
private:
    int id;
    int nif_cliente;
public:
    Venda(int id, int nif_cliente);
};

} // namespace model
