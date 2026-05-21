#include "../../include/model/Venda.h"
#include "../../include/model/Cliente.h"

Venda::Venda(int id, Cliente* cliente) {
    this->id = id;
    this->cliente = cliente;
}
