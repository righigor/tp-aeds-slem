#ifndef VEICULO_H
#define VEICULO_H

#include "../Local/Local.h"

class Veiculo {
  private:
    char placa[20];
    char modelo[20];
    bool status;
    Local* localAtual;

  public:

    // Contrutor da classe
    Veiculo(const char* _placa, const char* _modelo, bool _status, const Local& local);

    // Setters
    void setStatus(bool novoStatus);
    void setLocal(const Local& novo);

    // Getters
    const char* getPlaca() const;
    const char* getModelo() const;
    bool getStatus() const;
    Local getLocalAtual() const;

    void getVeiculo() const;
};

#endif