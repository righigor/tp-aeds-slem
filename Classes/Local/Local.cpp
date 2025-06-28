#include "Local.h"
#include <cstring>
#include <iostream>
using namespace std;

Local::Local(const char * nome, int x, int y)
{
    strncpy(this->nome, nome, sizeof(this->nome) - 1);
    this->nome[sizeof(this->nome) - 1] = '\0';
    this->coordenadaX = x;
    this->coordenadaY = y;
}

const char *Local::getNome() const
{
    return this->nome;
}
void Local::setNome(const char * novoNome)
{
    strncpy(this->nome, novoNome, sizeof(this->nome) - 1);
    this->nome[sizeof(this->nome) - 1] = '\0';
}
int Local::getlocalId() const {
    return this->localId;
}
void Local::setLocalId(int id) {
    this->localId = id;
}

int Local::getCoordenadaX() const {
    return this->coordenadaX;
}
int Local::getCoordenadaY() const {
    return this->coordenadaY;
}

void Local::setCoordenadaX(int X) {
    this->coordenadaX = X;
};
void Local::setCoordenadaY(int Y) {
    this->coordenadaY = Y;
};
void Local::getLocal() const {
    cout << "ID do local: " << this->localId << "\n" <<
            "Nome do local: " << this->nome << "\n" <<
            "Coordenada do local: " << 
            "X: " << this->coordenadaX << 
            ", Y: " << this->coordenadaY << endl;
}

