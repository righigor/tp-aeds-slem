#ifndef VEICULO_H
#define VEICULO_H

#include "../Local/Local.h"

class Veiculo {
  private:
    int veiculoId;
    char placa[20];
    char modelo[20];
    bool status;
    Local * localAtual;

  public:

    int getVeiculoId() const;
    void setVeiculoId(int id);

    // Contrutor da classe
    Veiculo(const char* _placa, const char* _modelo, bool _status, Local * local);
    Veiculo(bool status, Local * local);

    // Setters
    void setStatus(bool novoStatus);
    void setLocal(Local * novo);
    void setPlaca(const char * placa);

    // Getters
    const char* getPlaca() const;
    const char* getModelo() const;
    bool getStatus() const;
    Local * getLocalAtual() const;

    void getVeiculo() const;
};

#endif