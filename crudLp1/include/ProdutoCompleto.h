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
        void setNomeProduto(int nome);
        void setPrecoProduto(float preco);
        void setQtestoqueProduto(int qtd_estoque);
        void setMarcaProduto(int marca);
        void setPesoProduto(float preco);
        void setAno_lancamentoProduto(string ano_lancamento);
        void setFabricanteProduto(string fabricante);
        void setPotenciaProduto(float potencia);
};

#endif // PRODUTOCOMPLETO_H
