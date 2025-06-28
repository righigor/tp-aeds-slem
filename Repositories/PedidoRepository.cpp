#include "PedidoRepository.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int PedidoRepository::criar(Pedido &pedido) {
    pedido.setPedidoId(pedidos.size());
    pedido.setStatus("Pendente");
    pedidos.push_back(pedido);
    cout << "Pedido adicionado com sucesso. ID do pedido: " << pedido.getPedidoId() << endl;
    return pedido.getPedidoId();
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

void PedidoRepository::atualizarPedido(Pedido &pedido, int pedidoId) {
    for (size_t i = 0 ; i < pedidos.size() ; i++) {
        if (pedidos[i].getPedidoId() == pedidoId) {
            pedidos[i] = pedido;
            cout << "Pedido atualizado. ID do pedido: " << pedidoId << endl;
            break;
        }
    }
}

void PedidoRepository::getPedidosPendentes() {
    vector<Pedido> pendentes;
    for (const auto &pedido : pedidos) {
        if (strcmp(pedido.getStatus(), "Pendente") == 0) {
            pendentes.push_back(pedido);
        }
    }
    for (int i = 0; i < pendentes.size(); i++)
    {
        pendentes[i].getPedido();
    }
    
}