#ifndef ENTREGA_SERVICE_H
#define ENTREGA_SERVICE_H

#include "../Classes/Entrega/Entrega.h"
#include "../Services/PedidoService.h"
#include "../Services/VeiculoService.h"
#include "../Repositories/EntregaRepository.h"

class EntregaService {
    private:
    EntregaRepository &repository;
    public:
    EntregaService(EntregaRepository &repository);
    Entrega* criarEntrega(Pedido *pedido, Veiculo *veiculo);
    Entrega* buscarEntregaById(int entregaId);
};

#endif