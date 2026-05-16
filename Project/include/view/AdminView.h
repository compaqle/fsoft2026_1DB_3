#pragma once
#include <string>

class AdminView {
public:
    AdminView();
    int mostrarMenuAdmin();
    void printMensagem(const std::string& msg);
};
