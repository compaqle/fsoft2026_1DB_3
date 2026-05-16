#include "../../include/model/Venda.h"

Venda::Venda(int id, int nif_cliente) {
    this->id = id;
    this->nifCliente = std::to_string(nif_cliente);
}
