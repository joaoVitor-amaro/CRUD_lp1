#include "ProdutoEletronico.h"

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
        case 2:
            this->categoria = "Notebook";
        case 3:
            this->categoria = "Tablet";
        case 4:
            this->categoria = "Fone";
    }
}

string ProdutoEletronico::getMarca() {
    return this->marca;
}

string ProdutoEletronico::getCategoria() {
    return this->categoria;
}
