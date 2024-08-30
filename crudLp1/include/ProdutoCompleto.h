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
        string getNomeProduto();
        float getPrecoProduto();
        int getQtEstoqueProduto();
        string getMarcaProduto();
        float getPesoProduto();
        int getAnoLancamentoProduto();
        float getPotenciaProduto();
        void getIdNome();
        void setNomeProduto(int nome);
        void setPrecoProduto(float preco);
        void setQtestoqueProduto(int qtd_estoque);
        void setMarcaProduto(int marca);
        void setPesoProduto(float preco);
        void setAno_lancamentoProduto(int ano_lancamento);
        void setPotenciaProduto(float potencia);
        string salvarDadosArquivos();
};

#endif // PRODUTOCOMPLETO_H
