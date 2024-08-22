#include "ProdutoEletronico.h"
#include <iostream>
ProdutoEletronico::ProdutoEletronico(){}

ProdutoEletronico::ProdutoEletronico(int marca, int categoria) {
    this->setMarca(marca);
    this->setCategoria(categoria);
}

void ProdutoEletronico::setMarca(int marca) {
    switch (marca) {
        case 1:
            this->marca = "Samsung";
        case 2:
            this->marca = "Apple";
        case 3:
            this->marca = "Motorola";
        case 4:
            this->marca = "Nokia";
        case 5:
            this->marca = "Xiaomi";
    }
}

void ProdutoEletronico::setCategoria(int categoria) {
    switch (categoria) {
        case 1:
            this->categoria = "Smartphone";
            break;
        case 2:
            this->categoria = "Notebook";
            break;
        case 3:
            this->categoria = "Tablet";
            break;
        case 4:
            this->categoria = "Fone";
            break;
    }
}

string ProdutoEletronico::getMarca() {
    return this->marca;
}

string ProdutoEletronico::getCategoria() {
    return this->categoria;
}
void  ProdutoEletronico::leratributos(){
    int marca , categoria ;
    ItemIventario::leratributos();
    cin >> marca >> categoria ;
    this->setCategoria(categoria);
    this->setMarca(marca);
}
