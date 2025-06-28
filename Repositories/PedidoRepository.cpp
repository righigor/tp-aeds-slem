#include "PedidoRepository.h"
#include <iostream>
#include <algorithm>
using namespace std;

void PedidoRepository::criar(const Pedido &pedido) {
    pedidos.push_back(pedido);
    cout << "Pedido adicionado com sucesso. ID do pedido: " << pedido.getPedidoId() << endl;
}

void PedidoRepository::removerPedido(int pedidoId) {
    auto it = find_if(pedidos.begin(), pedidos.end(), [pedidoId](const Pedido &pedido) {
        return pedido.getPedidoId() == pedidoId;
    });
    if (it != pedidos.end()) {
        pedidos.erase(it);
        cout << "Pedido removido com sucesso. ID do pedido: " << pedidoId << endl;
    } else {
        cout << "Pedido não encontrado. ID do pedido: " << pedidoId << endl;
    }
}

Pedido* PedidoRepository::buscarPedido(int pedidoId) {
    auto it = find_if(pedidos.begin(), pedidos.end(), [pedidoId](const Pedido &pedido) {
        return pedido.getPedidoId() == pedidoId;
    });
    if (it != pedidos.end()) {
        return &(*it);
    }
    return nullptr;
}

vector<Pedido> PedidoRepository::listagem() {
    return pedidos;
}