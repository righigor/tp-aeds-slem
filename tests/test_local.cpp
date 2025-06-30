#include <iostream>
#include "../Classes/Local/Local.h"

int main() {
    std::cout << "== Iniciando testes da classe Local ==\n";

    Local local("TesteLocal", 5, 10);

    if (local.getNome() == std::string("TesteLocal") &&
        local.getX() == 5 &&
        local.getY() == 10) {
        std::cout << "[OK] Local criado corretamente com os atributos esperados.\n";
    } else {
        std::cout << "[ERRO] Local com valores incorretos.\n";
    }

    return 0;
}
