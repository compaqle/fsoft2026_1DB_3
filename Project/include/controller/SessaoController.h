#pragma once
#include <string>

class SessaoController {
private:
    std::string perfil; // "ADMIN" ou "CAIXA"
    int id_caixa;       // só usado quando perfil == "CAIXA"

public:
    SessaoController(std::string perfil, int id_caixa = -1);
    std::string getPerfil();
    int getIdCaixa();
};
