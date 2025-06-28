#ifndef LOCALREPOSITORY_H
#define LOCALREPOSITORY_H

#include "../Interfaces/IRepository.h"
#include "../Classes/Local/Local.h"
#include <vector>

class LocalRepository : public IRepository<Local> {
    private:
        std::vector<Local> locais;

    public:
        int criar(Local &local) override;
        void atualizar(Local &LocalAtualizado, int id) override;
        std::vector<Local> listagem() override;
        void deletar(int id) override;
        Local* ler(int id) override;

        void salvarEmArquivo();
        void carregarDoArquivo();
};

#endif