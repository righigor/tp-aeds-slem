#ifndef LOCALCONTROLLER_H
#define LOCALCONTROLLER_H

#include "../Services/LocalService.h"
#include <memory>

class LocalController {
private:
    LocalService &service;

public:
    LocalController(LocalService &service);

    void localPeloId();
    int criarLocal();
    void atualizarLocal();
    void deletarLocal();
    void listarTodos();
};

#endif