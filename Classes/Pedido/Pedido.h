#ifndef PEDIDO_H
#define PEDIDO_H

#include"../Local/Local.h"

class Pedido {
    private:
        int pedidoId;
        Local* localDeOrigem;
        Local* localDeDestino;
        double pesoDoItem;
        char status[20]; // "Pendente", "Em Transporte", "Entregue"
    public:
        Pedido(Local * origem, Local * destino, double peso);
        int getPedidoId() const;
        void setPedidoId(int id);
        Local * getLocalDeOrigem() const;
        Local * getLocalDeDestino() const;
        void setLocalDeOrigem(Local* origem);
        void setLocalDeDestino(Local* destino);
        double getPesoDoItem() const;
        void setPesoDoItem(double peso);
        const char* getStatus() const;
        void setStatus(const char* novoStatus);
        void getPedido() const;
};

#endif