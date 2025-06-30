# 📦 Sistema de Logística de Entrega de Mercadorias (SLEM)

![C++](https://img.shields.io/badge/Linguagem-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/Projeto-Acadêmico-success.svg)

Este é o projeto prático final da disciplina **Algoritmos e Estruturas de Dados I** do curso de Engenharia de Software da **PUC Minas**.

O sistema simula a logística de entrega de mercadorias, com foco na manipulação eficiente de dados, estruturas como vetores e arquivos binários, e implementação de um algoritmo simples de roteamento baseado em distância euclidiana.

---

## 👥 Colaboradores

- [Igor Righi](https://github.com/igor-righi)
- [Zaine Mendes](https://github.com/zainemt)

---

## ⚙️ Funcionalidades

### 📍 Locais
- **Atributos**: Nome, Coordenada X, Coordenada Y
- **Operações**: Cadastrar, listar, atualizar, remover

### 🚚 Veículos
- **Atributos**: Placa, Modelo, Status (disponível/ocupado), Local atual
- **Operações**: Cadastrar, listar, atualizar, remover

### 📦 Pedidos
- **Atributos**: ID, Local de origem, Local de destino, Peso
- **Operações**: Cadastrar, listar, atualizar, remover

### 🗺️ Entregas
- Calcula e exibe a rota ideal para um pedido com base na distância euclidiana
- Seleciona o veículo disponível mais próximo do local de origem
- Atualiza status do veículo e do pedido
- Simula a entrega e atualiza a posição final do veículo

---

## 💾 Persistência
Os dados de cada entidade são armazenados em **arquivos binários**, garantindo que os cadastros sejam mantidos entre execuções do sistema.

---

## 🖥️ Como compilar e executar

### Pré-requisitos:
- Linux (ou WSL)
- `g++` com suporte a C++17
- `make`

### Passos:

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/tp-aeds-slem.git
cd tp-aeds-slem

# Compile o projeto
make

# Execute o programa
./slem
```
---

### Estrutura de Pastas:
```
├── Classes/
│   ├── Local/
│   ├── Veiculo/
│   ├── Pedido/
│   └── Entrega/
├── Controller/
├── Repositories/
├── Services/
├── Utils/
├── data/
├── tests/
├── main.cpp
└── Makefile
```

---

## 📄 Licença

Este projeto foi desenvolvido exclusivamente para fins acadêmicos. Reutilização do código é permitida apenas para fins educacionais e com os devidos créditos.
