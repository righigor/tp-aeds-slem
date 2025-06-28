#include "LocalService.h"
#include<iostream>
using namespace std;

LocalService::LocalService(LocalRepository &repo) : repository(repo) {}

Local * LocalService::localPeloId(int id) {
    return repository.ler(id);
}

int LocalService::criar(Local &local) {
    return repository.criar(local);
}
void LocalService::atualizar(Local &LocalAtualizado, int id) {
    repository.atualizar(LocalAtualizado, id);
}

std::vector<Local> LocalService::listagem() {
    return repository.listagem();
}

void LocalService::deletar(int id) {
    repository.deletar(id);
}