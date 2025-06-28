#include <iostream>
#include <cstdlib>
#include "Classes/Local/Local.h"
#include "Classes/Pedido/Pedido.h"
#include "Classes/Veiculo/Veiculo.h"

#include "Controller/LocalController.h"
#include "Controller/VeiculoController.h"
#include "Controller/PedidoController.h"
#include "Controller/EntregaController.h"

#include "Repositories/LocalRepository.h"
#include "Repositories/VeiculoRepository.h"
#include "Repositories/PedidoRepository.h"
#include "Repositories/EntregaRepository.h"

#include "Services/LocalService.h"
#include "Services/VeiculoService.h"
#include "Services/PedidoService.h"
#include "Services/EntregaService.h"

using namespace std;

int main() {

    LocalRepository localRepository;
    LocalService localService(localRepository);
    LocalController localController(localService);

    VeiculoRepository veiculoRepository;
    VeiculoService veiculoService(veiculoRepository);
    VeiculoController veiculoController(veiculoService, localService);

    PedidoRepository pedidoRepository;
    PedidoService pedidoService(pedidoRepository);
    PedidoController pedidoController(pedidoService, localController, localService);

    EntregaRepository entregaRepository;
    EntregaService entregaService(entregaRepository);
    EntregaController entregaController(pedidoService, veiculoService, entregaService);

    int opcao;

    do {
        cout << "\n=== Sistema de Logística de Entrega de Mercadorias ===" << endl;
        cout << "1. Cadastrar local" << endl;
        cout << "2. Listar locais" << endl;
        cout << "3. Atualizar local" << endl;
        cout << "4. Remover local" << endl;

        cout << "5. Cadastrar veículo" << endl;
        cout << "6. Listar veículos" << endl;
        cout << "7. Atualizar veículo" << endl;
        cout << "8. Remover veículo" << endl;

        cout << "9. Cadastrar pedido" << endl;
        cout << "10. Listar pedidos" << endl;
        cout << "11. Atualizar pedido" << endl;
        cout << "12. Remover pedido" << endl;

        cout << "13. Realizar entrega" << endl;
        cout << "14. Backup de dados" << endl;
        cout << "15. Restaurar dados" << endl;

        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        cin.ignore();

        switch (opcao) {
            case 1:
                localController.criarLocal();
                localController.listarTodos();
                break;
            case 2:
                localController.listarTodos();
                break;
            case 3:
                localController.atualizarLocal();
                break;
            case 4:
                localController.deletarLocal();
                break;
            case 5:
                veiculoController.criarVeiculo();
                break;
            case 6:
                veiculoController.listarTodos();
                break;
            case 7:
                veiculoController.atualizarVeiculo();
                break;
            case 8:
                veiculoController.deletarVeiculo();
                break;
            case 9:
                pedidoController.criarPedido();
                break;
            case 10:
                pedidoController.listagemPedidos();
                break;
            case 11:
                pedidoController.atualizarPedido();
                break;
            case 12:
                pedidoController.removerPedido();
                break;

            case 13:
                entregaController.realizarEntrega();
                break;

            case 14:
                localRepository.salvarEmArquivo();
                veiculoRepository.salvarEmArquivo();
                pedidoRepository.salvarEmArquivo();
                cout << "Backup realizado com sucesso." << endl;
                break;

            case 15:
                localRepository.carregarDoArquivo();
                veiculoRepository.carregarDoArquivo(localRepository);
                pedidoRepository.carregarDoArquivo(localRepository);
                cout << "Dados restaurados com sucesso." << endl;
                break;

            case 0:
                cout << "Encerrando o programa..." << endl;
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
        cout << "\nPressione Enter para continuar...";
        cin.get();
        system("cls");
    } while (opcao != 0);

    return 0;
}
