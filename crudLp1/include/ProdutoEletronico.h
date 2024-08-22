#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H
#include <string>

using namespace std;

class ProdutoEletronico{
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
};

#endif // PRODUTOELETRONICO_H
