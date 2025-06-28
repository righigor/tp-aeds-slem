#ifndef LOCALCONTROLLER_H
#define LOCALCONTROLLER_H

#include "../Services/LocalService.h"

class LocalController {
private:
    LocalService &service;

public:
    LocalController(LocalService &service);

    void localPeloId();
    void criarLocal();
    void atualizarLocal();
    void deletarLocal();
    void listarTodos();
};

#endif