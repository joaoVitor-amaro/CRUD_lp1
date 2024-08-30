#include "ProdutoCompleto.h"
#include <iostream>
#include <string>

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

string ProdutoCompleto::getNomeProduto() {
    return this->prodr.getNome();
}

float ProdutoCompleto::getPrecoProduto() {
    return this->prodr.getPreco();
}

int ProdutoCompleto::getQtEstoqueProduto() {
    return this->prodr.getQtdEstoque();
}

string ProdutoCompleto::getMarcaProduto() {
    return this->prodr.getMarca();
}

float ProdutoCompleto::getPesoProduto() {
    return this->descricao.getpeso();
}

int ProdutoCompleto::getAnoLancamentoProduto() {
    return this->descricao.getdatadelancamento();
}

float ProdutoCompleto::getPotenciaProduto() {
    return this->descricao.getpotencia();
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

void ProdutoCompleto::setAno_lancamentoProduto(int ano_lancamento) {
    this->descricao.setdatadelancamento(ano_lancamento);
}

void ProdutoCompleto::setPotenciaProduto(float potencia) {
    this->descricao.setpotencia(potencia);
}

string ProdutoCompleto::salvarDadosArquivos() {
    //converter todos os atributos em string
    string dados = to_string(this->prodr.getId()) + " " + this->prodr.getNome()
    + " " + to_string(this->prodr.getPreco()) + " " + to_string(this->prodr.getQtdEstoque())
    + " " + this->prodr.getMarca() + " " + to_string(this->descricao.getpeso()) + " " +
    to_string(this->descricao.getdatadelancamento()) + " " + to_string(this->descricao.getpotencia());
    return dados;
}
