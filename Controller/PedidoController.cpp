# include "PedidoController.h"
#include <iostream>
using namespace std;

PedidoController::PedidoController(PedidoService &service, LocalController &localController) : service(service), localController(localController) {}

void PedidoController::criarPedido() {
    int pedidoId;
    shared_ptr<Local> localDeOrigem = localController.criarLocal();
    shared_ptr<Local> localDeDestino = localController.criarLocal();
    double peso;
    cout << "Digite o peso do pedido: ";
    cin >> peso;
    cout << "Digite o ID do pedido: ";
    cin >> pedidoId;
    Pedido pedido(pedidoId, localDeOrigem, localDeDestino, peso);
    service.criarPedido(pedido);
}

void PedidoController::removerPedido(int pedidoId) {
    service.removerPedido(pedidoId);
}

Pedido* PedidoController::buscarPedido(int pedidoId) {
    return service.buscarPedido(pedidoId);
}

std::vector<Pedido> PedidoController::listagemPedidos() {
    return service.listagemPedidos();
}