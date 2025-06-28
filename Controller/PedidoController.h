#ifndef PEDIDO_CONTROLLER_H
#define PEDIDO_CONTROLLER_H

#include "../Services/PedidoService.h"
#include "../Controller/LocalController.h"

class PedidoController {
    private:
        PedidoService &service;
        LocalController &localController;
    public:
        PedidoController(PedidoService &service, LocalController &localController);
        void criarPedido();
        void removerPedido(int pedidoId);
        Pedido* buscarPedido(int pedidoId);
        std::vector<Pedido> listagemPedidos();
};

#endif