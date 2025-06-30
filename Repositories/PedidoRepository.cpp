#include "PedidoRepository.h"
#include "../Repositories/LocalRepository.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
static int numeroDePedidos = 0;

int PedidoRepository::criar(Pedido &pedido) {
    pedido.setPedidoId(numeroDePedidos++);
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
            return;
        }
    }
    cout << "Pedido com ID " << pedidoId << " não encontrado." << endl;
}

void PedidoRepository::getPedidosPendentes() {
    vector<Pedido> pendentes;
    for (const auto &pedido : pedidos) {
        if (strcmp(pedido.getStatus(), "Pendente") == 0) {
            pendentes.push_back(pedido);
        }
    }
    for (size_t i = 0; i < pendentes.size(); i++)
    {
        pendentes[i].getPedido();
    }
    
}

void PedidoRepository::salvarEmArquivo() {
    string caminho = "data/pedidos.bin";
    ofstream arquivo(caminho, ios::binary | ios::trunc);
    if (!arquivo) {
        cerr << "Erro ao abrir arquivo para salvar pedidos.\n";
        return;
    }

    size_t tamanho = pedidos.size();
    arquivo.write(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    for (const Pedido& pedido : pedidos) {
        int id = pedido.getPedidoId();
        double peso = pedido.getPesoDoItem();
        const char* status = pedido.getStatus();
        int origemId = pedido.getLocalDeOrigem()->getlocalId();
        int destinoId = pedido.getLocalDeDestino()->getlocalId();

        arquivo.write(reinterpret_cast<char*>(&id), sizeof(int));
        arquivo.write(reinterpret_cast<const char*>(&peso), sizeof(double));
        arquivo.write(status, 20);
        arquivo.write(reinterpret_cast<char*>(&origemId), sizeof(int));
        arquivo.write(reinterpret_cast<char*>(&destinoId), sizeof(int));
    }

    arquivo.close();
    cout << "Pedidos salvos em: " << caminho << endl;
}

void PedidoRepository::carregarDoArquivo(LocalRepository& localRepo) {
    string caminho = "data/pedidos.bin";
    ifstream arquivo(caminho, ios::binary);
    if (!arquivo) {
        cerr << "Arquivo de pedidos não encontrado: " << caminho << endl;
        return;
    }

    size_t tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    pedidos.clear();
    for (size_t i = 0; i < tamanho; ++i) {
        int id, origemId, destinoId;
        double peso;
        char status[20];

        arquivo.read(reinterpret_cast<char*>(&id), sizeof(int));
        arquivo.read(reinterpret_cast<char*>(&peso), sizeof(double));
        arquivo.read(status, 20);
        arquivo.read(reinterpret_cast<char*>(&origemId), sizeof(int));
        arquivo.read(reinterpret_cast<char*>(&destinoId), sizeof(int));

        Local* origem = localRepo.ler(origemId);
        Local* destino = localRepo.ler(destinoId);

        Pedido pedido(origem, destino, peso);
        pedido.setPedidoId(id);
        pedido.setStatus(status);
        pedidos.push_back(pedido);
    }

    arquivo.close();
    cout << "Pedidos carregados de: " << caminho << endl;
}