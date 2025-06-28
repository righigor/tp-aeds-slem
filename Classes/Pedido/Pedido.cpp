#include "Pedido.h"
#include <cstring>
#include <iostream>
using namespace std;

#include "../Local/Local.h"

Pedido::Pedido(int pedidoId, Local * origem, Local * destino, double peso) {
    if (peso <= 0) {
        throw runtime_error("Peso inválido.");
    }
    if (origem == NULL || destino == NULL) {
        throw runtime_error("Objeto de origem ou destino inválido.");
    }
    this->pedidoId = pedidoId;
    this->localDeOrigem = origem;
    this->localDeDestino = destino;
    this->pesoDoItem = peso;
}
int Pedido::getPedidoId() const {
    return this->pedidoId;
}

const Local * Pedido::getLocalDeOrigem() const {
    return this->localDeOrigem;
}

const Local * Pedido::getLocalDeDestino() const {
    return this->localDeDestino;
}
double Pedido::getPesoDoItem() const {
    return this->pesoDoItem;
}