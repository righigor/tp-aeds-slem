#include <iostream>
#include <cmath>
#include "../Classes/Pedido/Pedido.h"
#include "../Classes/Local/Local.h"

bool assertEqual(double a, double b, std::string msg) {
    if (std::abs(a - b) < 1e-6) {
        std::cout << "[OK] " << msg << std::endl;
        return true;
    } else {
        std::cout << "[ERRO] " << msg << " Esperado: " << b << ", Obtido: " << a << std::endl;
        return false;
    }
}

bool assertTrue(bool condition, std::string msg) {
    if (condition) {
        std::cout << "[OK] " << msg << std::endl;
        return true;
    } else {
        std::cout << "[ERRO] " << msg << std::endl;
        return false;
    }
}

int main() {
    std::cout << "== Iniciando testes da classe Pedido ==" << std::endl;

    Local origem("Origem", 0, 0);
    Local destino("Destino", 3, 4);
    double peso = 10.5;

    Pedido p(&origem, &destino, peso);

    bool passed = true;
    passed &= assertEqual(p.getPesoDoItem(), 10.5, "Peso do pedido deve ser 10.5");
    passed &= assertTrue(p.getLocalDeOrigem() == &origem, "Origem deve ser o ponteiro correto");
    passed &= assertTrue(p.getLocalDeDestino() == &destino, "Destino deve ser o ponteiro correto");

    if (passed) {
        std::cout << "\nTodos os testes de Pedido passaram com sucesso. ✅" << std::endl;
        return 0;
    } else {
        std::cout << "\nAlguns testes de Pedido falharam. ❌" << std::endl;
        return 1;
    }
}
