#ifndef DESCRICAO_H
#define DESCRICAO_H
#include <bits/stdc++.h>

using namespace std;

class Descricao
{
    public:
        Descricao();
        Descricao(float peso, string data_de_lancamento, string fabricante,float potencia);

        float getpeso();
        string getdatadelancamento();
        string getfabricante();
        float getpotencia();

        void setpotencia(float potencia);
        void setpeso(float peso);
        void setdatadelancamento(string data_de_lancamento);
        void setfabricante(string fabricante);



    private:
        float potencia;
        float peso;
        string data_de_lancamento;
        string fabricante;
};

#endif // DESCRICAO_H
