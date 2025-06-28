#ifndef ENTREGA_H
#define ENTREGA_H

#include "../Pedido/Pedido.h"
#include "../Veiculo/Veiculo.h"

class Entrega {
    private:
        int entregaId;
        Pedido* pedido;
        Veiculo* veiculo;
        bool status; // 0 - Em Transporte, 1 - Entregue
    public:
        Entrega(Pedido* pedido, Veiculo* veiculo);
        void atualizarStatus(bool novoStatus);
        bool getStatus() const;
        Pedido* getPedido() const;
        Veiculo* getVeiculo() const;
        void getEntrega() const;
        void setPedido(Pedido* novoPedido);
        void setVeiculo(Veiculo* novoVeiculo);
        void setStatus(bool novoStatus);
        int getEntregaId() const;
        void setEntregaId(int id);
};

#endif