#include "Veiculo.h"
#include "../Local/Local.h"
#include <cstring>
#include <iostream>
using namespace std;

Veiculo::Veiculo(const char *_placa, const char *_modelo, bool _status, Local * local)
{
  strncpy(placa, _placa, sizeof(placa) - 1);
  placa[sizeof(placa) - 1] = '\0';
  strncpy(modelo, _modelo, sizeof(modelo) - 1);
  modelo[sizeof(modelo) - 1] = '\0';
  status = _status;
  localAtual = local;
}

Veiculo::Veiculo(bool status, Local * local) {
    this->status = status;
    this->localAtual = local;
}

void Veiculo::setStatus(bool novoStatus)
{
  status = novoStatus;
}

void Veiculo::setLocal(Local * novo)
{
  this->localAtual = novo;
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

Local * Veiculo::getLocalAtual() const
{
  return localAtual;
}
int Veiculo::getVeiculoId() const {
    return this->veiculoId;
}
void Veiculo::setVeiculoId(int id) {
    this->veiculoId = id;
}
void Veiculo::setPlaca(const char * placa) {
    strncpy(this->placa, placa, sizeof(this->placa) - 1);
    this->placa[sizeof(placa) - 1] = '\0';
}

void Veiculo::getVeiculo() const
{
  cout << "Placa: " << placa << "\n" <<
          "Modelo: " << modelo << "\n" <<
          "Status: " << (status ? "Disponível" : "Ocupado") << "\n" <<
          "Local Atual: \n";
          localAtual->getLocal();
}