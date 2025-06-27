#include "LocalController.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

LocalController::LocalController(LocalService &service) : service(service) {}

void LocalController::listarTodos() {
    std::vector<Local> locais = service.listagem();

    for (size_t i = 0 ; i < locais.size() ; i++) {
        cout << "ID: " << locais[i].getlocalId() << ", Nome: " << locais[i].getNome()
                  << ", Coordenadas: (" << locais[i].getCoordenadaX() << ", " << locais[i].getCoordenadaY() << ")\n";
    }
}

void LocalController::deletarLocal() {
    int id;
    cout << "Insira o id do local que deseja remover:";
    cin >> id;
    service.deletar(id);
}

void LocalController::criarLocal() {
    char nome[100];
    int x, y;

    cout << "Digite o nome do local: ";
    fgets(nome, sizeof(nome), stdin);
    cout << "Digite a coordenada X: ";
    cin >> x;
    cout << "Digite a coordenada Y: ";
    cin >> y;

    Local novoLocal(nome, x, y);
    service.criar(novoLocal);
    
}

void LocalController::atualizarLocal() {
    int id;
    cout << "Insira o id do local que deseja atualizar: ";
    cin >> id;

    char nome[100];
    int x, y;

    cout << "Digite o novo nome do local: ";
    fgets(nome, sizeof(nome), stdin);
    cout << "Digite a nova coordenada X: ";
    cin >> x;
    cout << "Digite a nova coordenada Y: ";
    cin >> y;

    Local novoLocal(nome, x, y);
    service.atualizar(novoLocal, id);

}