#ifndef ENTREGA_CONTROLLER_H
#define ENTREGA_CONTROLLER_H

#include "../Services/PedidoService.h"
#include "../Services/VeiculoService.h"
#include "../Services/EntregaService.h"

class EntregaController {
    private:
    PedidoService &pedidoService;
    VeiculoService &veiculoService;
    EntregaService &entregaService;
    public:
    EntregaController(PedidoService &pedidoService, VeiculoService &veiculoService, EntregaService &entregaService);
    void realizarEntrega();
    void finalizarEntrega(int entregaId);
};

#endif