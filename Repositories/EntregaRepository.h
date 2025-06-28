#ifndef ENTREGA_REPOSITORY_H
#define ENTREGA_REPOSITORY_H

#include "../Classes/Entrega/Entrega.h"
#include <vector>

class EntregaRepository {
    private:
    std::vector<Entrega*> entregas;
    public:
    Entrega* criarEntrega(Pedido* pedido, Veiculo* veiculo);
    Entrega* buscarEntregaById(int entregaId);
};

#endif