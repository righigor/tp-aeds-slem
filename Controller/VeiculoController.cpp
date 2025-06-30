#include "VeiculoController.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

VeiculoController::VeiculoController(VeiculoService &service, LocalService &localService)
    : service(service), localService(localService) {}


void VeiculoController::listarTodos() {
    std::vector<Veiculo> veiculos = service.listagem();

    if (veiculos.size() == 0) {
        cout << "Não há veículos criados." << endl;
    } else {
        cout << "===== Lista de veículos =====" << endl;
        for (size_t i = 0 ; i < veiculos.size() ; i++) {
            veiculos[i].getVeiculo();
        }
    }
}

void VeiculoController::criarVeiculo() {
    char placa[20];
    char modelo[100];
    bool status;
    int idLocal;

    cout << "Digite a placa do veículo: ";
    cin.ignore();
    fgets(placa, sizeof(placa), stdin);
    cout << "Digite o modelo do veículo: ";
    fgets(modelo, sizeof(modelo), stdin);
    cout << "Status do veículo (1 = Disponível, 0 = Ocupado): ";
    cin >> status;
    cout << "ID do local atual do veículo: ";
    cin >> idLocal;

    Local* local = localService.localPeloId(idLocal);
    if (!local) {
        cout << "Local não encontrado!\n";
        return;
    }

    Veiculo novoVeiculo(placa, modelo, status, local);
    service.criar(novoVeiculo);
}

void VeiculoController::deletarVeiculo() {
    int id;
    cout << "Insira o id do veículo que deseja remover:";
    cin >> id;
    service.deletar(id);
}

void VeiculoController::atualizarVeiculo() {
    bool status;
    int idLocal, idVeiculo;

    cout << "Insira o id do veículo que queira atualizar: ";
    cin >> idVeiculo;
    cout << "Insira o novo status do veículo (1 = Disponível, 0 = Ocupado): ";
    cin >> status;
    cout << "Insira o id do novo local:";
    cin >> idLocal;
    
    Local * local = localService.localPeloId(idLocal);
    if (!local) {
        cout << "Local não encontrado!\n";
        return;
    }

    Veiculo veiculoAtualizado(status, local);
    service.atualizar(veiculoAtualizado, idVeiculo);
}

void VeiculoController::veiculoPeloId() {
    int id;
    cout << "Insira o id do veículo que deseja consultar:";
    cin >> id;
    Veiculo * veiculo = service.veiculoPeloId(id);
    veiculo->getVeiculo();
}