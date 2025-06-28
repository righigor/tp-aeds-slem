#ifndef PEDIDO_CONTROLLER_H
#define PEDIDO_CONTROLLER_H

#include "../Services/PedidoService.h"
#include "../Controller/LocalController.h"
#include "../Services/LocalService.h"

class PedidoController {
    private:
        PedidoService &service;
        LocalController &localController;
        LocalService &localService;
    public:
        PedidoController(PedidoService &service, LocalController &localController, LocalService &localService);
        void criarPedido();
        void atualizarPedido();
        void removerPedido();
        void buscarPedido();
        void listagemPedidos();
};

#endif