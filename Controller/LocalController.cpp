#include "LocalController.h"
#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

LocalController::LocalController(LocalService &service) : service(service) {}

void LocalController::localPeloId() {
    int id;
    cout << "Insira o id do local que deseja consultar:";
    cin >> id;
    Local * local = service.localPeloId(id);
    local->getLocal();
}

void LocalController::listarTodos() {
    std::vector<Local> locais = service.listagem();

    if (locais.size() == 0) {
        cout << "Não há locais criados." << endl;
    } else {
        cout << "===== Lista de locais =====" << endl;
        for (size_t i = 0 ; i < locais.size() ; i++) {
            locais[i].getLocal();
        }
    }
    
}

void LocalController::deletarLocal() {
    int id;
    cout << "Insira o id do local que deseja remover:";
    cin >> id;
    service.deletar(id);
}

int LocalController::criarLocal() {
    char nome[100];
    int x, y;

    cout << "Digite o nome do local: ";
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    cout << "Digite a coordenada X: ";
    cin >> x;
    cout << "Digite a coordenada Y: ";
    cin >> y;
    cin.ignore();

    Local novoLocal(nome, x, y);
    int id = service.criar(novoLocal);
    return id;
}

void LocalController::atualizarLocal() {
    int id;
    cout << "Insira o id do local que deseja atualizar: ";
    cin >> id;

    char nome[100];
    int x, y;

    cout << "Digite o novo nome do local: ";
    cin.ignore();
    fgets(nome, sizeof(nome), stdin);
    cout << "Digite a nova coordenada X: ";
    cin >> x;
    cout << "Digite a nova coordenada Y: ";
    cin >> y;
    cin.ignore();
    
    Local novoLocal(nome, x, y);
    service.atualizar(novoLocal, id);

}