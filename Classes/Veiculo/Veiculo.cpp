#include "Veiculo.h"
#include "../Local/Local.h"
#include <cstring>
#include <iostream>
using namespace std;

Veiculo::Veiculo(const char *_placa, const char *_modelo, bool _status, const Local &local)
{
  strncpy(placa, _placa, sizeof(placa) - 1);
  placa[sizeof(placa) - 1] = '\0';
  strncpy(modelo, _modelo, sizeof(modelo) - 1);
  modelo[sizeof(modelo) - 1] = '\0';
  status = _status;
  localAtual = new Local(local);
}

void Veiculo::setStatus(bool novoStatus)
{
  status = novoStatus;
}

void Veiculo::setLocal(const Local &novo)
{
  *localAtual = novo;
}

const char *Veiculo::getPlaca() const
{
  return placa;
}

const char *Veiculo::getModelo() const
{
  return modelo;
}

bool Veiculo::getStatus() const
{
  return status;
}

Local Veiculo::getLocalAtual() const
{
  return *localAtual;
}

void Veiculo::getVeiculo() const
{
  cout << "Placa: " << placa << "\n";
  cout << "Modelo: " << modelo << "\n";
  cout << "Status: " << (status ? "Disponível" : "Ocupado") << "\n";
  cout << "Local Atual: ";
  localAtual->getLocal();
}