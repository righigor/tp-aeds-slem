#include "VeiculoRepository.h"
#include "../Repositories/LocalRepository.h"
#include <iostream>
#include <fstream>
using namespace std;
static int numeroDeVeiculos = 0;

int VeiculoRepository::criar(Veiculo &veiculo) {
    veiculo.setVeiculoId(numeroDeVeiculos++);
    veiculos.push_back(veiculo);
    cout << "Veículo adicionado com sucesso. ID do veículo: " << veiculo.getVeiculoId() << endl;
    return veiculo.getVeiculoId();
};
void VeiculoRepository::atualizar(Veiculo &veiculoAtualizado, int id) {
    for (size_t i = 0 ; i < veiculos.size() ; i++) {
        if (veiculos[i].getVeiculoId() == id) {
            veiculos[i].setLocal(veiculoAtualizado.getLocalAtual());
            veiculos[i].setStatus(veiculoAtualizado.getStatus());
            cout << "Veículo atualizado. Id do veículo: " << id << endl;
            return;
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

std::vector<Veiculo> VeiculoRepository::getVeiculosDisponiveis() const {
    std::vector<Veiculo> veiculosDisponiveis;
    for (const auto &veiculo : veiculos) {
        if (veiculo.getStatus()) {
            veiculosDisponiveis.push_back(veiculo);
        }
    }
    return veiculosDisponiveis;
}

void VeiculoRepository::salvarEmArquivo() {
    string caminho = "data/veiculos.bin";
    ofstream arquivo(caminho, ios::binary | ios::trunc);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para escrita: " << caminho << endl;
        return;
    }

    size_t tamanho = veiculos.size();
    arquivo.write(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    for (const auto& veiculo : veiculos) {
        const char* placa = veiculo.getPlaca();
        const char* modelo = veiculo.getModelo();
        bool status = veiculo.getStatus();
        int localId = veiculo.getLocalAtual()->getlocalId();

        arquivo.write(placa, 20);
        arquivo.write(modelo, 20);
        arquivo.write(reinterpret_cast<char*>(&status), sizeof(bool));
        arquivo.write(reinterpret_cast<char*>(&localId), sizeof(int));
    }

    arquivo.close();
    cout << "Veículos salvos em: " << caminho << endl;
}

void VeiculoRepository::carregarDoArquivo(LocalRepository& localRepo) {
    string caminho = "data/veiculos.bin";
    ifstream arquivo(caminho, ios::binary);
    if (!arquivo) {
        cerr << "Arquivo de veículos não encontrado: " << caminho << endl;
        return;
    }

    size_t tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    veiculos.clear();
    veiculos.reserve(tamanho);

    for (size_t i = 0; i < tamanho; ++i) {
        char placa[20];
        char modelo[20];
        bool status;
        int localId;

        arquivo.read(placa, 20);
        arquivo.read(modelo, 20);
        arquivo.read(reinterpret_cast<char*>(&status), sizeof(bool));
        arquivo.read(reinterpret_cast<char*>(&localId), sizeof(int));

        Local* local = nullptr;
        try {
            local = localRepo.ler(localId);
        } catch (const exception& e) {
            cerr << "Erro: Local com ID " << localId << " não encontrado. Ignorando veículo.\n";
            continue;
        }

        Veiculo veiculo(placa, modelo, status, local);
        veiculo.setVeiculoId(static_cast<int>(i));
        veiculos.push_back(veiculo);
    }

    arquivo.close();
    cout << "Veículos carregados de: " << caminho << endl;
}