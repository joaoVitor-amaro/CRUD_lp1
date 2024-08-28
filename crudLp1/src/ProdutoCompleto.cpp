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

void ProdutoCompleto::setNomeProduto(int nome) {
    this->prodr.setNome(nome);
}

void ProdutoCompleto::setPrecoProduto(float preco) {
    this->prodr.setPreco(preco);
}

void ProdutoCompleto::setQtestoqueProduto(int qtd_estoque) {
    this->prodr.setQtdEstoque(qtd_estoque);
}

void ProdutoCompleto::setMarcaProduto(int marca) {
    this->prodr.setMarca(marca);
}

void ProdutoCompleto::setPesoProduto(float peso) {
    this->descricao.setpeso(peso);
}

void ProdutoCompleto::setAno_lancamentoProduto(string ano_lancamento) {
    this->descricao.setdatadelancamento(ano_lancamento);
}

void ProdutoCompleto::setFabricanteProduto(string fabricante) {
    this->descricao.setfabricante(fabricante);
}

void ProdutoCompleto::setPotenciaProduto(float potencia) {
    this->descricao.setpotencia(potencia);
}
