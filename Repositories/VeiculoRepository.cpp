#include "VeiculoRepository.h"
#include <iostream>
using namespace std;

void VeiculoRepository::criar(Veiculo &veiculo) {
    veiculo.setVeiculoId(veiculos.size());
    veiculos.push_back(veiculo);
};
void VeiculoRepository::atualizar(Veiculo &veiculoAtualizado, int id) {
    for (size_t i = 0 ; i < veiculos.size() ; i++) {
        if (veiculos[i].getVeiculoId() == id) {
            veiculos[i].setLocal(veiculoAtualizado.getLocalAtual());
            veiculos[i].setPlaca(veiculoAtualizado.getPlaca());
            cout << "Veículo atualizado. Id do veículo: " << id << endl;
            break;
        }
    }
    cout << "Veículo com ID " << id << " não encontrado." << endl;
};
std::vector<Veiculo> VeiculoRepository::listagem() {
    return veiculos;
};
void VeiculoRepository::deletar(int id) {
    for (size_t i = 0 ; i < veiculos.size() ; i++) {
        if (veiculos[i].getVeiculoId() == id) {
            veiculos.erase(veiculos.begin() + i);
            cout << "Veículo com ID " << id << " removido.\n";
            return;
        }
    }
    std::cout << "Veículo com ID " << id << " não encontrado.\n";
};
Veiculo * VeiculoRepository::ler(int id) {

    for (size_t i = 0 ; i < veiculos.size() ; i++) {
       if (veiculos[i].getVeiculoId() == id) {
            return &veiculos[i];
       }
    }
    throw runtime_error("Erro ao encontrar o veículo");

};
