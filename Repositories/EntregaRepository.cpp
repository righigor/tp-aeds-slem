#include "EntregaRepository.h"
#include <iostream>
using namespace std;
static int numeroDeEntregas = 0;

Entrega* EntregaRepository::criarEntrega(Pedido* pedido, Veiculo* veiculo) {
    Entrega* entrega = new Entrega(pedido, veiculo);
    entrega->setEntregaId(numeroDeEntregas++);
    entrega->atualizarStatus(false);
    entregas.push_back(entrega);
    return entrega;
}

Entrega* EntregaRepository::buscarEntregaById(int entregaId) {
    for (auto& entrega : entregas) {
        if (entrega->getEntregaId() == entregaId) {
            return entrega;
        }
    }
    return nullptr;
}