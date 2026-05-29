#pragma once
#include <string>
#include <vector>
#include "../dto/CaixaDTO.h"

class View {
public:
    View();

    int menuPrincipal(const std::vector<CaixaDTO>& caixas);
    int menuAdmin();
    int menuCaixa();

    void printMensagem(const std::string& msg);
};
