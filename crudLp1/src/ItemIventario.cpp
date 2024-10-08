#include "ItemIventario.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std ;
ItemIventario::ItemIventario(){}

ItemIventario::ItemIventario(int id, int nome, float preco, int qtd_estoque){
    this->id = id;
    this->setNome(nome);
    this->preco = preco;
    this->qtd_estoque = qtd_estoque;
}

int ItemIventario::getId() {
    return this->id;
}

string ItemIventario::getNome() {
    return this->nome;
}

float ItemIventario::getPreco() {
    return this->preco;
}

int ItemIventario::getQtdEstoque() {
    return this->qtd_estoque;
}

void ItemIventario::setNome(int nome) {
    switch (nome) {
        case 1:
            this->nome = "Smartphone";
            break;
        case 2:
            this->nome = "Notebook";
            break;
        case 3:
            this->nome = "Tablet";
            break;
        case 4:
            this->nome = "Fone";
            break;
    }
}

void ItemIventario::setPreco(float preco) {
    this->preco = preco;
}

void ItemIventario::setQtdEstoque(int qtd_estoque) {
    this->qtd_estoque = qtd_estoque;
}

 void ItemIventario::exibirDados() {
    cout << left << setw(5) << this->id;
    cout << left << setw(13) << this->nome;
    cout << "R$" << left << setw(6) <<this->preco;
    cout << left << setw(10) << this->qtd_estoque;
 }
