#include"Entrega.h"
#include <iostream>
using namespace std;
Entrega::Entrega(Pedido *pedido, Veiculo *veiculo) {
    if (pedido == NULL || veiculo == NULL) {
        throw runtime_error("Pedido ou veículo inválido.");
    }
    this->pedido = pedido;
    this->veiculo = veiculo;
    this->status = false;
}
void Entrega::atualizarStatus(bool novoStatus) {
    this->status = novoStatus;
}
bool Entrega::getStatus() const {
    return this->status;
}
Pedido* Entrega::getPedido() const {
    return this->pedido;
}
Veiculo* Entrega::getVeiculo() const {
    return this->veiculo;
}
void Entrega::getEntrega() const {
    cout << "ID da Entrega: " << this->getEntregaId() << endl;
    cout << "Pedido ID: " << this->pedido->getPedidoId() << endl;
    cout << "Veículo ID: " << this->veiculo->getVeiculoId() << endl;
    cout << "Status da Entrega: " << (this->status ? "Entregue" : "Em Transporte") << endl;
    this->pedido->getPedido();
    this->veiculo->getVeiculo();
}
void Entrega::setPedido(Pedido* novoPedido) {
    if (novoPedido == NULL) {
        throw runtime_error("Pedido inválido.");
    }
    this->pedido = novoPedido;
}
void Entrega::setVeiculo(Veiculo* novoVeiculo) {
    if (novoVeiculo == NULL) {
        throw runtime_error("Veículo inválido.");
    }
    this->veiculo = novoVeiculo;
}
void Entrega::setStatus(bool novoStatus) {
    this->status = novoStatus;
}
int Entrega::getEntregaId() const {
    return this->entregaId;
}
void Entrega::setEntregaId(int id) {
    this->entregaId = id;
}