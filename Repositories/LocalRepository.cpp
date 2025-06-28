#include "LocalRepository.h"
#include<iostream>
using namespace std;

Local* LocalRepository::ler(int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
       if (locais[i].getlocalId() == id) {
            return &locais[i];
       }
    }
    throw runtime_error("Erro ao encontrar o local");
}

int LocalRepository::criar(Local &local)
{
    local.setLocalId(locais.size());
    locais.push_back(local);
    return local.getlocalId();
}

void LocalRepository::atualizar(Local &LocalAtualizado, int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
        if (locais[i].getlocalId() == id) {
            locais[i].setNome(LocalAtualizado.getNome());
            locais[i].setCoordenadaX(LocalAtualizado.getCoordenadaX());
            locais[i].setCoordenadaY(LocalAtualizado.getCoordenadaY());
            
            cout << "Local atualizado. Id do local: " << id << endl;
            break;
        }
    }
    cout << "Local com ID " << id << " não encontrado." << endl;
};

std::vector<Local> LocalRepository::listagem() {
    return locais;
};

void LocalRepository::deletar(int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
        if (locais[i].getlocalId() == id) {
            locais.erase(locais.begin() + i);
            cout << "Local com ID " << id << " removido.\n";
            return;
        }
    }
    std::cout << "Local com ID " << id << " não encontrado.\n";
};