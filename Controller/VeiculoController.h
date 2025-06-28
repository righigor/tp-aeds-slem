#ifndef VEICULOCONTROLLER_H
#define VEICULOCONTROLLER_H

#include "../Services/VeiculoService.h"
#include "../Services/LocalService.h"

class VeiculoController {
private:
    VeiculoService &service;
    LocalService &localService;

public:
    VeiculoController(VeiculoService &service, LocalService &localService);

    void veiculoPeloId();
    void criarVeiculo();
    void atualizarVeiculo();
    void deletarVeiculo();
    void listarTodos();
};

#endif