#include "Pedido.h"
#include <cstring>
#include <iostream>
using namespace std;

#include "../Local/Local.h"

Pedido::Pedido(Local * origem, Local * destino, double peso) {
    if (peso <= 0) {
        throw runtime_error("Peso inválido.");
    }
    /*
        if (origem == NULL || destino == NULL) {
        throw runtime_error("Objeto de origem ou destino inválido.");
        }
    */
    this->localDeOrigem = origem;
    this->localDeDestino = destino;
    this->pesoDoItem = peso;
    strcpy(this->status, "Pendente");
}
int Pedido::getPedidoId() const {
    return this->pedidoId;
}

void Pedido::setPedidoId(int id) {
    this->pedidoId = id;
}

Local * Pedido::getLocalDeOrigem() const {
    return this->localDeOrigem;
}

Local * Pedido::getLocalDeDestino() const {
    return this->localDeDestino;
}
double Pedido::getPesoDoItem() const {
    return this->pesoDoItem;
}

const char* Pedido::getStatus() const {
    return this->status;
}

void Pedido::setStatus(const char* novoStatus) {
    if (strcmp(novoStatus, "Pendente") == 0 || strcmp(novoStatus, "Em Transporte") == 0 || strcmp(novoStatus, "Entregue") == 0) {
        strncpy(this->status, novoStatus, sizeof(this->status) - 1);
        this->status[sizeof(this->status) - 1] = '\0';
    } else {
        throw runtime_error("Status inválido.");
    }
}
void Pedido::getPedido() const {
    cout << "Pedido ID: " << this->pedidoId << endl;
    cout << "Local de Origem: " << this->localDeOrigem->getNome() << endl;
    cout << "Local de Destino: " << this->localDeDestino->getNome() << endl;
    cout << "Peso do Item: " << this->pesoDoItem << endl;
    cout << "Status: " << (this->status ? this->status : "Indefinido") << endl;
}

void Pedido::setLocalDeOrigem(Local* origem) {
    if (origem == NULL) {
        throw runtime_error("Objeto de origem inválido.");
    }
    this->localDeOrigem = origem;
}

void Pedido::setLocalDeDestino(Local* destino) {
    if (destino == NULL) {
        throw runtime_error("Objeto de destino inválido.");
    }
    this->localDeDestino = destino;
}

void Pedido::setPesoDoItem(double peso) {
    if (peso <= 0) {
        throw runtime_error("Peso inválido.");
    }
    this->pesoDoItem = peso;
}