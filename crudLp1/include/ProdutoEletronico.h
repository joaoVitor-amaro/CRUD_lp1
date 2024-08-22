#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H
#include <string>
#include "ItemIventario.h"
using namespace std;

class ProdutoEletronico : public ItemIventario{
    private:
        string marca;
        string categoria;
    public:
        ProdutoEletronico();
        ProdutoEletronico(int marca, int categoria);
        void setMarca(int marca);
        void setCategoria(int categoria);
        string getMarca();
        string getCategoria();


        void leratributos() override ;
};

#endif // PRODUTOELETRONICO_H
