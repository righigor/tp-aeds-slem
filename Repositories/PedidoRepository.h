#ifndef PEDIDO_REPOSITORY_H
#define PEDIDO_REPOSITORY_H

#include "../Interfaces/IRepository.h"
#include "../Classes/Pedido/Pedido.h"
#include <vector>

class PedidoRepository {
    private:
        std::vector<Pedido> pedidos;
    public:
        int criar(Pedido &pedido);
        void removerPedido(int pedidoId);
        Pedido* buscarPedido(int pedidoId);
        std::vector<Pedido> listagem();
        void atualizarPedido(Pedido &pedido, int pedidoId);
        void getPedidosPendentes();
};

#endif