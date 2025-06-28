#ifndef UTILS_H
#define UTILS_H

#include "../Classes/Local/Local.h"
#include "../Classes/Veiculo/Veiculo.h"
#include <vector>

float calcularDistanciaEuclidiana(Local * v1, Local * v2);
Veiculo* encontrarVeiculoMaisProximo(const std::vector<Veiculo>& veiculos, Local * local);

#endif