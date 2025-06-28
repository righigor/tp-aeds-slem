#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H

#include "../Repositories/LocalRepository.h"

class LocalService
{
private:
    LocalRepository &repository;

public:
    LocalService(LocalRepository &repository);
    Local* localPeloId(int id);
    int criar(Local &local);
    void atualizar(Local &LocalAtualizado, int id);
    std::vector<Local> listagem();
    void deletar(int id);
};

#endif