#ifndef PEDIDO_H
#define PEDIDO_H

#include"../Local/Local.h"

class Pedido {
    private:
        int pedidoId;
        shared_ptr<Local> localDeOrigem;
        shared_ptr<Local> localDeDestino;
        double pesoDoItem;
    public:
        Pedido(int pedidoId, shared_ptr<Local> origem, shared_ptr<Local> destino, double peso);
        int getPedidoId() const;
        const Local * getLocalDeOrigem() const;
        const Local * getLocalDeDestino() const;
        double getPesoDoItem() const;
        
};

#endif