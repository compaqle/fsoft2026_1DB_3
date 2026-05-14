#pragma once
#include "Utilizador.h"

class Admin : public Utilizador {
public:
    static const int ADMIN_DEFAULT_ID = 0;

    Admin();
};
