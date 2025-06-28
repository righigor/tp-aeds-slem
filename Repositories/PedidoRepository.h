#ifndef PEDIDO_REPOSITORY_H
#define PEDIDO_REPOSITORY_H

#include "../Interfaces/IRepository.h"
#include "../Classes/Pedido/Pedido.h"
#include <vector>

class PedidoRepository : public IRepository<Pedido> {
    private:
        std::vector<Pedido> pedidos;
    public:
        void criar(const Pedido &pedido);
        void removerPedido(int pedidoId);
        Pedido* buscarPedido(int pedidoId);
        std::vector<Pedido> listagem();
};

#endif