#include "PedidoService.h"
#include <vector>

PedidoService::PedidoService(PedidoRepository &repository) : repository(repository) {}

int PedidoService::criarPedido(Pedido &pedido) {
    return repository.criar(pedido);
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

void PedidoService::atualizarPedido(Pedido &pedido, int pedidoId) {
    repository.atualizarPedido(pedido, pedidoId);
}

void PedidoService::getPedidosPendentes() {
    repository.getPedidosPendentes();
}