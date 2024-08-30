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
        void opcaoAtualizar();
        void menuAtualizarProduto();
        int buscarIdProduto(int idProduto);
        int tipoNomeProduto(string nomeStr);
        int tipoMarcaProduto(string marcaStr);
        void menuPesquisar();
        void dadosProdutospesqu(int i);
        void adcionarProduto(int id, int nome, float preco, int qt_estoque, int marca, float peso, int data_lacamento, float potencia);
        void listarProduto();
        void pesquisarProduto();
        void atualizarProduto(int opcao, int pos);
        void deletarProduto();
        void adicionarDadosArquivos();
        void lerArquivo();
};

#endif // PRODUTO_H
