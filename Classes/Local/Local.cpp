#include "Local.h"
#include <cstring>
#include <iostream>
using namespace std;

Local::Local(char * nome, int x, int y)
{
    strncpy(this->nome, nome, sizeof(nome) - 1);
    this->nome[sizeof(this->nome) - 1] = '\0';
    this->coordenadaX = x;
    this->coordenadaY = y;
}

const char *Local::getNome() const
{
    return this->nome;
}
void Local::setNome(char * novoNome)
{
    strncpy(this->nome, novoNome, sizeof(this->nome) - 1);
    this->nome[sizeof(this->nome) - 1] = '\0';
}

int Local::getCoordenadaX() const {
    return this->coordenadaX;
}
int Local::getCoordenadaY() const {
    return this->coordenadaY;
}
void Local::getLocal() const {
    cout << "Nome do local: " << this->nome << "\n" <<
            "Coordenada do local: " << 
            "X: " << this->coordenadaX << 
            ", Y: " << this->coordenadaY << endl;
}

