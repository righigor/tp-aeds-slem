#include "EntregaRepository.h"
#include <iostream>
using namespace std;

Entrega* EntregaRepository::criarEntrega(Pedido* pedido, Veiculo* veiculo) {
    Entrega* entrega = new Entrega(pedido, veiculo);
    entrega->setEntregaId(entregas.size());
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