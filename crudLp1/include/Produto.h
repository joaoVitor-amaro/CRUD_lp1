#ifndef PRODUTO_H
#define PRODUTO_H
#include <vector>
#include "ItemIventario.h"
#include "Descricao.h"
#include "ProdutoCompleto.h"

class Produto{
    private:
        vector<ProdutoCompleto> inventario;
    public:
        Produto();
        void menu();
        void menuOpcao();
        void adcionarProduto();
        void listarProduto();
};

#endif // PRODUTO_H
