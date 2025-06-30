# include "PedidoController.h"
#include <iostream>
using namespace std;

PedidoController::PedidoController(PedidoService &service, LocalController &localController, LocalService &localService) : service(service), localController(localController), localService(localService) {}

void PedidoController::criarPedido() {
    int idOrigem, idDestino;
    double peso;
    cout << "Criar Pedido" << endl;
    cout << "Digite o ID do local de origem: ";
    cin >> idOrigem;
    cout << "Digite o ID do local de destino: ";
    cin >> idDestino;
    cout << "Digite o peso do item (kg): ";
    cin >> peso;
    Local* localDeOrigem = localService.localPeloId(idOrigem);
    Local* localDeDestino = localService.localPeloId(idDestino);
    if (!localDeOrigem || !localDeDestino) {
        cout << "Erro: Criação do pedido falhou." << endl;
        return;
    }
    Pedido pedido(localDeOrigem, localDeDestino, peso);
    service.criarPedido(pedido);
}

void PedidoController::removerPedido() {
    int pedidoId;
    cout << "Insira o ID do pedido que deseja remover: ";
    cin >> pedidoId;
    service.removerPedido(pedidoId);
}

void PedidoController::buscarPedido() {
    int pedidoId;
    cout << "Insira o ID do pedido que deseja buscar: ";
    cin >> pedidoId;
    Pedido * pedido = service.buscarPedido(pedidoId);
    pedido->getPedido();
}

void PedidoController::listagemPedidos() {
    vector<Pedido> pedidos = service.listagemPedidos();

    if (pedidos.size() == 0) {
        cout << "Não há pedidos criados." << endl;
    } else {
        cout << "===== Lista de pedidos =====" << endl;
        for (size_t i = 0 ; i < pedidos.size() ; i++) {
            pedidos[i].getPedido();
        }
    }
}

void PedidoController::atualizarPedido() {
    int pedidoId;
    cout << "Insira o ID do pedido que deseja atualizar: ";
    cin.ignore();
    cin >> pedidoId;
    Pedido* pedido = service.buscarPedido(pedidoId);
    if (!pedido) {
        cout << "Pedido não encontrado." << endl;
        return;
    }

    int idOrigem = localController.criarLocal();
    int idDestino = localController.criarLocal();
    double peso;
    cout << "Digite o novo peso do item (kg): ";
    cin >> peso;

    Local* localDeOrigem = localService.localPeloId(idOrigem);
    Local* localDeDestino = localService.localPeloId(idDestino);
    
    if (!localDeOrigem || !localDeDestino) {
        cout << "Erro: Atualização do pedido falhou." << endl;
        return;
    }
    char novoStatus[100];
    cout << "Digite o novo status do pedido (Pendente, Em Transporte, Entregue): ";
    cin.ignore();
    cin.getline(novoStatus, sizeof(novoStatus));

    pedido->setLocalDeOrigem(localDeOrigem);
    pedido->setLocalDeDestino(localDeDestino);
    pedido->setPesoDoItem(peso);
    pedido->setStatus(novoStatus);
    cout << "Pedido atualizado com sucesso." << endl;
}