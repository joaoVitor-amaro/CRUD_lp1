#ifndef ITEMIVENTARIO_H
#define ITEMIVENTARIO_H
#include <string>

using namespace std;

class ItemIventario{
    protected:
        int id = 0;
        string nome;
        float preco;
        int qtd_estoque;
    public:
        ItemIventario();
        ItemIventario(std::string nome, float preco, int qtd_estoque);
        string getNome();
        float getPreco();
        int getQtdEstoque();
        void setNome(string nome);
        void setPreco(float preco);
        void setQtdEstoque(int qtd_estoque);
};

#endif // ITEMIVENTARIO_H
