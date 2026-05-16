#pragma once
#include <string>

class View {
public:
    View();

    int menuPrincipal();
    int menuAdmin();
    int menuCaixa();

    void printMensagem(const std::string& msg);
};
