#ifndef PRODUTOELETRONICO_H
#define PRODUTOELETRONICO_H
#include <string>
#include "ItemIventario.h"
using namespace std;

class ProdutoEletronico : public ItemIventario{
    protected:
        string marca;
    public:
        ProdutoEletronico();
        ProdutoEletronico(int id, int nome, float preco, int qt_estoque, int marca);
        void setMarca(int marca);
        string getMarca();
        void exibirDados() override;
};

#endif // PRODUTOELETRONICO_H
