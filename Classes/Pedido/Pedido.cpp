#include "Pedido.h"
#include <cstring>
#include <iostream>
using namespace std;

#include "../local/Local.h"

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