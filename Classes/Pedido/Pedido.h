#ifndef PEDIDO_H
#define PEDIDO_H

#include"../Local/Local.h"

class Pedido {
    private:
        int pedidoId;
        Local * localDeOrigem;
        Local * localDeDestino;
        double pesoDoItem;
    public:
        Pedido(int pedidoId, Local * origem, Local * destino, double peso);
        int getPedidoId() const;
        const Local * getLocalDeOrigem() const;
        const Local * getLocalDeDestino() const;
        
};

#endif