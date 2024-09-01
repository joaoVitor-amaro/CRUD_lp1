#include "ProdutoEletronico.h"
#include <iostream>
#include "ItemIventario.h"
#include <iomanip>

ProdutoEletronico::ProdutoEletronico(){}

ProdutoEletronico::ProdutoEletronico(int id, int nome, float preco, int qt_estoque, int marca) : ItemIventario(id, nome, preco, qt_estoque) {
    this->id = id;
    this->setNome(nome);
    this->preco = preco;
    this->qtd_estoque = qt_estoque;
    this->setMarca(marca);
}

void ProdutoEletronico::setMarca(int marca) {
    switch (marca) {
        case 1:
            this->marca = "Samsung";
            break;
        case 2:
            this->marca = "Apple";
            break;
        case 3:
            this->marca = "Motorola";
            break;
        case 4:
            this->marca = "Nokia";
            break;
        case 5:
            this->marca = "Xiaomi";
            break;
    }
}

string ProdutoEletronico::getMarca() {
    return this->marca;
}

void ProdutoEletronico::exibirDados() {
    ItemIventario::exibirDados();
    cout << left << setw(10) << this->marca;
}
