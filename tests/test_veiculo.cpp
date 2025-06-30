#include <iostream>
#include "../Classes/Local/Local.h"
#include "../Classes/Veiculo/Veiculo.h"

int main() {
    std::cout << "== Iniciando testes da classe Veiculo ==\n";

    Local localAtual("LocalInicial", 2, 2);
    Veiculo veiculo("ABC1234", "Modelo X", "disponivel", &localAtual);

    if (veiculo.getPlaca() == std::string("ABC1234") &&
        veiculo.getModelo() == std::string("Modelo X") &&
        veiculo.getStatus() == std::string("disponivel") &&
        veiculo.getLocalAtual() == &localAtual) {
        std::cout << "[OK] Veículo criado corretamente com os atributos esperados.\n";
    } else {
        std::cout << "[ERRO] Veículo com dados incorretos.\n";
    }

    return 0;
}
