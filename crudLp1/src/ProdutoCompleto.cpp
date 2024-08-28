#include "ProdutoCompleto.h"

ProdutoCompleto::ProdutoCompleto(){}

ProdutoCompleto::ProdutoCompleto(ProdutoEletronico prodr, Descricao descricao) {
    this->prodr = prodr;
    this->descricao = descricao;
}

void ProdutoCompleto::exibirDados() {
    this->prodr.exibirDados();
    this->descricao.exibirDados();
}

int ProdutoCompleto::getIdProduto() {
    return this->prodr.getId();
}

void ProdutoCompleto::getIdNome() {
    cout << this->prodr.getId() << " - " << this->prodr.getNome() << endl;
}
