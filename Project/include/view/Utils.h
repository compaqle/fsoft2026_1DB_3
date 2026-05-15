#pragma once
#include <string>

class Utils {
public:
    static int lerInt(const std::string& mensagem);
    static double lerDouble(const std::string& mensagem);
    static std::string lerString(const std::string& mensagem);
};
