# include <iostream>

# include "Classes/Local/Local.h"
# include "Classes/Pedido/Pedido.h"
# include "Classes/Veiculo/Veiculo.h"
#include "Controller/LocalController.h"

using namespace std;

int main() {

    LocalRepository repository;
    LocalService service(repository);
    LocalController controller(service);

    controller.criarLocal();

}
