#include "VeiculoService.h"
#include<iostream>
using namespace std;

VeiculoService::VeiculoService(VeiculoRepository &repo) : repository(repo) {}

Veiculo * VeiculoService::veiculoPeloId(int id) {
    return repository.ler(id);
}

void VeiculoService::criar(Veiculo &veiculo) {
    repository.criar(veiculo);
}
void VeiculoService::atualizar(Veiculo &veiculoAtualizado, int id) {
    repository.atualizar(veiculoAtualizado, id);
}

std::vector<Veiculo> VeiculoService::listagem() {
    return repository.listagem();
}

void VeiculoService::deletar(int id) {
    repository.deletar(id);
}

std::vector<Veiculo> VeiculoService::getVeiculosDisponiveis() const {
    return repository.getVeiculosDisponiveis();
}