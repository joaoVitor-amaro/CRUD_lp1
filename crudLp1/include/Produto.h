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
        //void opcaoAtualizar();
        int buscarIdProduto(int idProduto);
        void menuPesquisar();
        void dadosProdutospesqu(int i);
        void adcionarProduto();
        void listarProduto();
        void pesquisarProduto();
        //void atualizarProduto();
        void deletarProduto();
};

#endif // PRODUTO_H
