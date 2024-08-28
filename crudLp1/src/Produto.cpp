#include "Produto.h"
#include <iostream>
#include <string>
#include "ProdutoEletronico.h"
#include "Descricao.h"
#include "ProdutoCompleto.h"
#include "ItemIventario.h"
#include <vector>

using namespace std;

Produto::Produto(){}

void Produto::menuOpcao() {
    cout << "-----------------------------" << endl;
    cout << "[1] - Inserir Produto" << endl;
    cout << "[2] - Listar Produtos" << endl;
    cout << "[3] - Pesquisar Produto" << endl;
    cout << "[4] - Atualizar Produtos" << endl;
    cout << "[5] - Remover Produto" << endl;
    cout << "[6] - Exibir Relatório" << endl;
    cout << "[7] - Sair" << endl;
    cout << "-----------------------------" << endl;
}

void Produto::listarProduto() {
    if(this->inventario.empty()) {
        cout << "Nenhum produto cadastrado" << endl;
    } else {
        cout << "ID - NOME - PRECO - ESTOQUE - MARCA - LANCAMENTO - FABRICANTE - POTENCIA" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        for(int i = 0; i < this->inventario.size(); i++) {
            this->inventario[i].exibirDados();
            cout << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;
    }
}

void Produto::pesquisarProduto() {
    menuPesquisar();
    int idProduto;
    cout << "Id: ";
    cin >> idProduto;
    int i = buscarIdProduto(idProduto); //Busca o id do produto
    dadosProdutospesqu(i); //Exibi os dados pesquisados do produto
}

void Produto::deletarProduto() {
    menuPesquisar();
    int idProdDeletar;
    cout << "Deletar id: ";
    cin >> idProdDeletar;
    int i = buscarIdProduto(idProdDeletar);
    this->inventario.erase(this->inventario.begin() + i);
}

int Produto::buscarIdProduto(int idProduto) {
    int identificador = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getIdProduto() == idProduto) {
            identificador = i;
        }
    }
    return identificador;
}

void Produto::menuPesquisar() {
    cout << "===== Produto =====" << endl;
    for(int i = 0; i < this->inventario.size(); i++) {
        this->inventario[i].getIdNome();
    }
    cout << "-----------------------" << endl;
}

void Produto::dadosProdutospesqu(int i) {
    cout << "---------------------------------------------------------------------" << endl;
    this->inventario[i].exibirDados();
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
}

void Produto::menu() {
    int opcao;
    while(true) {
        menuOpcao();
        cout << "Opcao: ";
        cin >> opcao;

        if(opcao == 7) {
            return;

        } else if(opcao == 1) {
            int id, nome, qt_estoque, marca;
            float preco, potencia, peso;
            string fabricante, data_lacamento;
            ItemIventario ive;
            ProdutoEletronico prodr;
            cout << "ID: ";
            cin >> id;
            ive.menuProduto();
            cout << "Nome: ";
            cin >> nome;
            cout << "Preco: ";
            cin >> preco;
            cout << "Quantidade em Estoque: ";
            cin >> qt_estoque;
            prodr.menuMarca();
            cout << "Marca: ";
            cin >> marca;
            cout << "Digite o peso: ";
            cin >> peso;
            cin.ignore();
            cout << "Digite a data de lancamento: ";
            getline(cin, data_lacamento);
            cout << "Digite o fabricante: ";
            getline(cin, fabricante);
            cout << "Digite a potencia: ";
            cin >> potencia;
            ProdutoEletronico prod = ProdutoEletronico(id, nome, preco, qt_estoque, marca);
            Descricao desc = Descricao(peso, data_lacamento, fabricante, potencia);
            ProdutoCompleto prodCom = ProdutoCompleto(prod, desc);
            inventario.push_back(prodCom);
        } else if(opcao == 2) {
            listarProduto();
        } else if(opcao == 3) {
            if(this->inventario.empty()) {
                cout << "Nenhum produto cadastrado" << endl;
            } else {
                pesquisarProduto();
            }
        } else if(opcao == 4) {
            if(this->inventario.empty()) {
                cout << "Sem Produtos" << endl;
            } else {
                cout << "Atualizer" << endl;
            }
        } else if(opcao == 5) {
            if(this->inventario.empty()) {
                cout << "Sem produtos" << endl;
            } else {
                deletarProduto();
            }
        } else if(opcao == 6) {
            cout << "Exibir relatório" << endl;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}
