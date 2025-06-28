#include "EntregaController.h"
#include <iostream>
#include <string>
#include <cstring>
#include "../utils/utils.h"
#include "../Classes/Entrega/Entrega.h"

using namespace std;

EntregaController::EntregaController(PedidoService &pedidoService, VeiculoService &veiculoService, EntregaService &entregaService) : pedidoService(pedidoService), veiculoService(veiculoService), entregaService(entregaService) {}

void EntregaController::realizarEntrega() {
    pedidoService.getPedidosPendentes();
    int pedidoId;
    cout << "Insira o ID do pedido que deseja entregar: ";
    cin >> pedidoId;

    Pedido* pedido = pedidoService.buscarPedido(pedidoId);

    if (pedido == nullptr || strcmp(pedido->getStatus(), "Pendente") != 0) {
        cout << "Pedido não encontrado ou não está pendente." << endl;
        return;
    }

    vector<Veiculo> veiculosDisponiveis = veiculoService.getVeiculosDisponiveis();
    Veiculo* veiculo = encontrarVeiculoMaisProximo(veiculosDisponiveis, pedido->getLocalDeDestino());
    veiculo->getVeiculo();
    veiculo->setStatus(false);
    pedido->setStatus("Em Transporte");
    Entrega* entrega = entregaService.criarEntrega(pedido, veiculo);
    entrega->getEntrega();
    finalizarEntrega(entrega->getEntregaId());
}

void EntregaController::finalizarEntrega(int entregaId) {
    Entrega* entrega = entregaService.buscarEntregaById(entregaId);
    if (entrega == nullptr || entrega->getStatus()) {
        cout << "Entrega não encontrada ou já finalizada." << endl;
        return;
    }
    entrega->atualizarStatus(true);
    Veiculo* veiculo = entrega->getVeiculo();
    veiculo->setStatus(true);
    veiculo->setLocal((entrega->getPedido()->getLocalDeDestino()));
    Pedido* pedido = entrega->getPedido();
    pedido->setStatus("Entregue");

    cout << "Entrega finalizada com sucesso!" << endl;
}