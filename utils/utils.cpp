#include "utils.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

float calcularDistanciaEuclidiana(Local * v1, Local * v2) {
    float dx = v2->getCoordenadaX() - v1->getCoordenadaX();
    float dy = v2->getCoordenadaY() - v1->getCoordenadaY();
    return sqrt(dx * dx + dy * dy);
}

Veiculo* encontrarVeiculoMaisProximo(const vector<Veiculo>& veiculos, Local * local) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo disponível." << endl;
        return nullptr;
    }

    Veiculo* veiculoMaisProximo = nullptr;
    float menorDistancia = std::numeric_limits<float>::max();

    for (const auto& veiculo : veiculos) {
        float distancia = calcularDistanciaEuclidiana(veiculo.getLocalAtual(), local);
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            veiculoMaisProximo = const_cast<Veiculo*>(&veiculo);
        }
    }

    return veiculoMaisProximo;
}