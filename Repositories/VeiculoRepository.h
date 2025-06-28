#ifndef VEICULOREPOSITORY_H
#define VEICULOREPOSITORY_H

#include "../Classes/Veiculo/Veiculo.h"
#include "../Interfaces/IRepository.h"
#include "../Repositories/LocalRepository.h"
#include <vector>

class VeiculoRepository : public IRepository<Veiculo> {

    private:
        std::vector<Veiculo> veiculos;

    public:
        int criar(Veiculo &Veiculo) override;
        void atualizar(Veiculo &veiculoAtualizado, int id) override;
        std::vector<Veiculo> listagem() override;
        void deletar(int id) override;
        Veiculo * ler(int id) override;
        std::vector<Veiculo> getVeiculosDisponiveis() const;

        void salvarEmArquivo();
        void carregarDoArquivo(LocalRepository& localRepo);
};


#endif
