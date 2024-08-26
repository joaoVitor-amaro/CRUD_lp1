#include "ProdutoEletronico.h"
#include <iostream>
#include "ItemIventario.h"

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


void ProdutoEletronico::menuMarca() {
    cout << "------------------" << endl;
    cout << "     Marca" << endl;
    cout << "------------------" << endl;
    cout << "[1] - Samsung" << endl;
    cout << "[2] - Apple" << endl;
    cout << "[3] - Motorola" << endl;
    cout << "[4] - Nokia" << endl;
    cout << "[5] - Xiaomi" << endl;
}

void ProdutoEletronico::exibirDados() {
    ItemIventario::exibirDados();
    cout << "Marca: " << this->marca << " - ";
}
