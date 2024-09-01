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
        //Menus
        void menu();
        void menuOpcao();
        void opcaoAtualizar();
        void menuAtualizarProduto();
        void menuPesquisar();
        void menuProduto();
        void menuMarca();

        int buscarIdProduto(int idProduto); //M�todo para buscar o id
        int tipoNomeProduto(string nomeStr); //M�todo que retorna o tipo do nome do produto em inteiro das possiveis op��es
        int tipoMarcaProduto(string marcaStr); //M�todo que retorna o tipo da marca do produto em inteiro das possiveis op��es
        int verificarIdExistente(int id); //Verifica se existe um id cadastrado antes de criar um novo produto
        int selecionarTipoProduto(int nome); //Verifica se o user escolheu uma das op��es existentes
        int selecionarTipoMarca(int marca);//Verifica se o user escolheu uma das op��es existentes
        //M�todo de cadastrar os atributos da superclasse e subclasses no vetor, formando um produto
        void adcionarProduto(int id, int nome, float preco, int qt_estoque, int marca, float peso, int data_lacamento, float potencia);
        void listarProduto(); //Listar todos os dados cadastrados no vetor
        void dadosProdutospesqu(int i); //Lista os dados do produto que o user pesquisou
        void pesquisarProduto(); //M�todo de pesquisa um produto espec�fico a partir do id
        void atualizarProduto(int opcao, int pos); //M�todo para atualizar um atributo especifico do produto
        void deletarProduto(); //M�todo de deletar o produto
        void adicionarDadosArquivos(); //Adiciona os dados do vetor no arquivo
        void lerArquivo(); //Ler os dados do arquivo e armazena no vetor

        //M�todos para saber a quantidade dos produtos e exibir no relat�rio
        int qtdEstoqueTotal();
        int qtdSmartphoneTotal();
        int qtdNoteTotal();
        int qtdTabletTotal();
        int qtdFoneTotal();
        int qtdSamsungTotal();
        int qtdAppleTotal();
        int qtdMotorolaTotal();
        int qtdNokiaTotal();
        int qtdXiaomiTotal();

        void exibirRelatorio(); //M�todo de exibir o relat�rio
};

#endif // PRODUTO_H
