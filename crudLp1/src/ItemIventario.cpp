#include "ItemIventario.h"
#include <string>
#include <iostream>
using namespace std ;
ItemIventario::ItemIventario(){}

ItemIventario::ItemIventario(string nome, float preco, int qtd_estoque){
    this->id++;
    this->nome = nome;
    this->preco = preco;
    this->qtd_estoque = qtd_estoque;
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

void ItemIventario::setNome(string nome) {
    this->nome = nome;
}

void ItemIventario::setPreco(float preco) {
    this->preco = preco;
}

void ItemIventario::setQtdEstoque(int qtd_estoque) {
    this->qtd_estoque = qtd_estoque;
}
 void ItemIventario::leratributos(){
     //cin.ignore();
     getline(cin,this->nome);
     cin >> this->preco ;
     cin >> this->qtd_estoque;
 }
