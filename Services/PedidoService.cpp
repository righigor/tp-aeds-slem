#include "PedidoService.h"

PedidoService::PedidoService(PedidoRepository &repository) : repository(repository) {}

void PedidoService::criarPedido(const Pedido &pedido) {
    repository.criar(pedido);
}

void PedidoService::removerPedido(int pedidoId) {
    repository.removerPedido(pedidoId);
}

Pedido* PedidoService::buscarPedido(int pedidoId) {
    return repository.buscarPedido(pedidoId);
}

std::vector<Pedido> PedidoService::listagemPedidos() {
    return repository.listagem();
}