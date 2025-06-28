# include <iostream>

# include "Classes/Local/Local.h"
# include "Classes/Pedido/Pedido.h"
# include "Classes/Veiculo/Veiculo.h"
#include "Controller/LocalController.h"
#include "Controller/VeiculoController.h"

using namespace std;

int main() {

    LocalRepository localRepository;
    LocalService localService(localRepository);
    LocalController localController(localService);

    VeiculoRepository veiculoRepository;
    VeiculoService veiculoService(veiculoRepository);
    VeiculoController veiculoController(veiculoService, localService);

    localController.criarLocal();
    localController.listarTodos();

    veiculoController.criarVeiculo();
    veiculoController.listarTodos();

}
