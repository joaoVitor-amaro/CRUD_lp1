#include "Produto.h"
#include <iostream>
#include <string>
#include "ProdutoEletronico.h"
#include "Descricao.h"
//#include "ProdutoCompleto.h"
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
    for (auto item : inventario) {
        item.exibirDados();
        cout << endl;
    }
}

void Produto::menu() {
    int opcao;
    while(true) {
        menuOpcao();
        cout << "Opcao: ";
        cin >> opcao;

        if(opcao == 0) {
            return;

        } else if(opcao == 1) {
            int id, nome, qt_estoque, marca;
            float preco, potencia, peso;
            string fabricante, data_lacamento;
            cout << "ID: ";
            cin >> id;
            cout << "Nome: ";
            cin >> nome;
            cout << "Preco: ";
            cin >> preco;
            cout << "Quantidade em Estoque: ";
            cin >> qt_estoque;
            cout << "Marcar: ";
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
            cout << "Pesquisar" << endl;
        } else if(opcao == 4) {
            cout << "Atualizar" << endl;
        } else if(opcao == 5) {
            cout << "Excluir" << endl;
        } else if(opcao == 6) {
            cout << "Exibir relatório" << endl;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}
