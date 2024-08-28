#ifndef PRODUTOCOMPLETO_H
#define PRODUTOCOMPLETO_H
#include "ProdutoEletronico.h"
#include "Descricao.h"
#include <string>

using namespace std;

class ProdutoCompleto{
    private:
        ProdutoEletronico prodr;
         Descricao descricao;
    public:
        ProdutoCompleto();
        ProdutoCompleto(ProdutoEletronico prodr, Descricao descricao);
        void exibirDados();
        int getIdProduto();
        void getIdNome();
};

#endif // PRODUTOCOMPLETO_H
