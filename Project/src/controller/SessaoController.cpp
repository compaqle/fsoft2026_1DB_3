#include "../../include/controller/SessaoController.h"

SessaoController::SessaoController(std::string perfil, int id_caixa) {
    this->perfil = perfil;
    this->id_caixa = id_caixa;
}

std::string SessaoController::getPerfil() { return perfil; }
int SessaoController::getIdCaixa() { return id_caixa; }
