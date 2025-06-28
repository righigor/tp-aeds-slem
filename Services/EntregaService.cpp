#include "EntregaService.h"
#include <iostream>
using namespace std;


EntregaService::EntregaService(EntregaRepository &repository) : repository(repository) {}

Entrega* EntregaService::criarEntrega(Pedido *pedido, Veiculo *veiculo) {
    return repository.criarEntrega(pedido, veiculo);
}

Entrega* EntregaService::buscarEntregaById(int entregaId) {
    return repository.buscarEntregaById(entregaId);
}