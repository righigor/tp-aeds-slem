#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H

#include "../Repositories/VeiculoRepository.h"

class VeiculoService
{
private:
    VeiculoRepository &repository;

public:
    VeiculoService(VeiculoRepository &repository);
    void criar(Veiculo &local);
    void atualizar(Veiculo &veiculoAtualizado, int id);
    std::vector<Veiculo> listagem();
    void deletar(int id);
    Veiculo * veiculoPeloId(int id);
    std::vector<Veiculo> getVeiculosDisponiveis() const;
};

#endif