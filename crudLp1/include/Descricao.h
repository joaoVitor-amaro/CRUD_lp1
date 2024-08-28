#ifndef DESCRICAO_H
#define DESCRICAO_H
#include <bits/stdc++.h>
#include "ItemIventario.h"
#include "ProdutoEletronico.h"
using namespace std;

class Descricao : public ItemIventario{
    public:
        Descricao();
        Descricao(float peso, int data_de_lancamento, float potencia);

        float getpeso();
        int getdatadelancamento();
        float getpotencia();

        void setpotencia(float potencia);
        void setpeso(float peso);
        void setdatadelancamento(int data_de_lancamento);

        void exibirDados();


    protected:
        float potencia;
        float peso;
        int data_de_lancamento;
        string fabricante;
};

#endif // DESCRICAO_H
