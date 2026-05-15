#include "../../include/view/Utils.h"
#include <iostream>
#include <limits>

int Utils::lerInt(const std::string& mensagem) {
    int valor;
    std::cout << mensagem;
    while (!(std::cin >> valor)) {
        std::cout << "Erro! Insira um numero inteiro: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::cin.ignore();
    return valor;
}

double Utils::lerDouble(const std::string& mensagem) {
    double valor;
    std::cout << mensagem;
    while (!(std::cin >> valor)) {
        std::cout << "Erro! Insira um numero: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::cin.ignore();
    return valor;
}

std::string Utils::lerString(const std::string& mensagem) {
    std::string valor;
    std::cout << mensagem;
    std::getline(std::cin, valor);
    return valor;
}
