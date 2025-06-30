#include "LocalRepository.h"
#include<iostream>
#include <fstream>
using namespace std;
static int numeroDeLocais = 0;

Local* LocalRepository::ler(int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
       if (locais[i].getlocalId() == id) {
            return &locais[i];
       }
    }
    throw runtime_error("Erro ao encontrar o local");
}

int LocalRepository::criar(Local &local)
{
    local.setLocalId(numeroDeLocais++);
    locais.push_back(local);
    return local.getlocalId();
}

void LocalRepository::atualizar(Local &LocalAtualizado, int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
        if (locais[i].getlocalId() == id) {
            locais[i].setNome(LocalAtualizado.getNome());
            locais[i].setCoordenadaX(LocalAtualizado.getCoordenadaX());
            locais[i].setCoordenadaY(LocalAtualizado.getCoordenadaY());
            
            cout << "Local atualizado. Id do local: " << id << endl;
            return;
        }
    }
    cout << "Local com ID " << id << " não encontrado." << endl;
};

std::vector<Local> LocalRepository::listagem() {
    return locais;
};

void LocalRepository::deletar(int id) {
    for (size_t i = 0 ; i < locais.size() ; i++) {
        if (locais[i].getlocalId() == id) {
            locais.erase(locais.begin() + i);
            cout << "Local com ID " << id << " removido.\n";
            return;
        }
    }
    std::cout << "Local com ID " << id << " não encontrado.\n";
};

void LocalRepository::salvarEmArquivo() {
    string caminho = "data/locais.bin";
    ofstream arquivo(caminho, ios::binary | ios::trunc);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para escrita: " << caminho << endl;
        return;
    }

    size_t tamanho = locais.size();
    arquivo.write(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    for (const auto& local : locais) {
        arquivo.write(reinterpret_cast<const char*>(&local), sizeof(Local));
    }

    arquivo.close();
    cout << "Locais salvos em: " << caminho << endl;
}

void LocalRepository::carregarDoArquivo() {
    string caminho = "data/locais.bin";
    ifstream arquivo(caminho, ios::binary);
    if (!arquivo) {
        cerr << "Arquivo de locais não encontrado: " << caminho << endl;
        return;
    }

    size_t tamanho = 0;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(size_t));

    locais.clear();
    locais.reserve(tamanho);

    for (size_t i = 0; i < tamanho; ++i) {
        Local localTemp("", 0, 0);
        arquivo.read(reinterpret_cast<char*>(&localTemp), sizeof(Local));
        locais.push_back(localTemp);
    }

    arquivo.close();
    cout << "Locais carregados de: " << caminho << endl;
}