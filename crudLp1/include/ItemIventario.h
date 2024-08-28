#ifndef ITEMIVENTARIO_H
#define ITEMIVENTARIO_H
#include <string>

using namespace std;

class ItemIventario{
    protected:
        int id;
        string nome;
        float preco;
        int qtd_estoque;
    public:
        ItemIventario();
        ItemIventario(int id, int nome, float preco, int qtd_estoque);
        int getId();
        string getNome();
        float getPreco();
        int getQtdEstoque();
        void setNome(int nome);
        void setPreco(float preco);
        void setQtdEstoque(int qtd_estoque);
        void menuProduto();
        virtual void exibirDados();
};

#endif // ITEMIVENTARIO_H
