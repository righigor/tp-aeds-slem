#ifndef PEDIDO_SERVICE_H
#define PEDIDO_SERVICE_H

#include "../Repositories/PedidoRepository.h"

class PedidoService {
    private:
        PedidoRepository &repository;
    public:
        PedidoService(PedidoRepository &repository);
        int criarPedido(Pedido &pedido);
        void removerPedido(int pedidoId);
        Pedido* buscarPedido(int pedidoId);
        std::vector<Pedido> listagemPedidos();
        void atualizarPedido(Pedido &pedido, int pedidoId);
        void getPedidosPendentes();
};

#endif