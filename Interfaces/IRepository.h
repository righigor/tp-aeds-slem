#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include<vector>

template<typename T>
class IRepository {
public:
    virtual int criar(T & obj) = 0;
    virtual T* ler(int id) = 0;
    virtual void atualizar(T &obj, int id) = 0;
    virtual std::vector<T> listagem() = 0;
    virtual void deletar(int id) = 0;
};

#endif