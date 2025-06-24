# Sistema de Logística de Entrega de Mercadorias (SLEM)
![C++](https://img.shields.io/badge/feito%20com-C%2B%2B-blue.svg)



O objetivo deste trabalho é desenvolver um Sistema de Logística de Entrega de Mercadorias
utilizando os conceitos de algoritmos e estruturas de dados aprendidos na disciplina de
Algoritmos e Estruturas de Dados I. O sistema deverá simular o gerenciamento de pedidos,
veículos e locais, com foco na manipulação eficiente de dados e na implementação de um
algoritmo de roteamento básico.

## Funcionalidades
- **Cadastro de Locais**: 
  - Atributos: Nome(id: "São Paulo", "Rua A, 123), coordenada X(numérica), coordenada Y(numérica).
  - Operações: Adicionar, remover e listar locais.

- **Cadastro de Veículos**:
  - Atributos: Placa(id), modelo, status (disponível, ocupado), local atual (ref a um Local cadastrado).
  - Operações: Adicionar, remover e listar veículos., Atualizar status do veículo.

- **Cadastro de Pedidos**:
  - Atributos: ID do pedido, local de origem (ref a um Local cadastrado), local de destino (ref a um Local cadastrado), peso do item (em kg).
  - Operações: Adicionar, remover e listar pedidos.

- **Cálculo e Exibição de Rota de Entrega**:
  - Dado um Pedido pendente, o sistema deve calcular e mostrar a rota de entrega a partir do veículo disponível mais próximo do local de origem do pedido.
  - A distância entre dois locais (cidades, pontos de entrega, etc.) será calculada utilizando a distância euclidiana entre suas coordenadas (X, Y).
  - A rota deve indicar o veículo selecionado, o local de origem do pedido, o local de destino do pedido e a distância total percorrida.
  - Após o cálculo da rota e a "simulação" da entrega, o sistema deve atualizar o status do veículo para ocupado e, ao final da entrega, o status deve retornar a disponível e seu local atual deve ser atualizado para o local de destino do pedido.
