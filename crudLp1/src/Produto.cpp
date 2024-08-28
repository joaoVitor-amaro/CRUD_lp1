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


void Produto::opcaoAtualizar() {
    cout << "[1] - Nome" << endl;
    cout << "[2] - Preco" << endl;
    cout << "[3] - Quantidade de estoque" << endl;
    cout << "[4] - Marca" << endl;
    cout << "[5] - Peso" << endl;
    cout << "[6] - Ano lancamento" << endl;
    cout << "[7] - Potencia" << endl;
}

void Produto::menuAtualizarProduto() {
    menuPesquisar();
    int id;
    int opcao;
    cout << "Informe o id";
    cin >> id;
    opcaoAtualizar();
    cout << "Opcao: ";
    cin >> opcao;
    int pos = buscarIdProduto(id);
    atualizarProduto(opcao, pos);
}

void Produto::atualizarProduto(int opcao, int pos) {
    ProdutoEletronico prodEle;
    switch (opcao) {
        case 1:
            prodEle.menuProduto();
            int nome;
            cout << "Nome: ";
            cin >> nome;
            this->inventario[pos].setNomeProduto(nome);
            break;
        case 2:
            float preco;
            cout << "Preco: ";
            cin >> preco;
            this->inventario[pos].setPrecoProduto(preco);
            break;
        case 3:
            int qtd_estoque;
            cout << "Quantidade de Estoque: ";
            cin >> qtd_estoque;
            this->inventario[pos].setQtestoqueProduto(qtd_estoque);
            break;
        case 4:
            int marca;
            prodEle.menuMarca();
            cout << "Marca: ";
            cin >> marca;
            this->inventario[pos].setMarcaProduto(marca);
            break;
        case 5:
            float peso;
            cout << "Peso: ";
            cin >> peso;
            this->inventario[pos].setPesoProduto(peso);
            break;
        case 6:
            int ano_lancamento;
            cout << "Ano de lacamento: ";
            cin >> ano_lancamento;
            this->inventario[pos].setAno_lancamentoProduto(ano_lancamento);
            break;
        case 7:
            float potencia;
            cout << "Potencia: ";
            cin >> potencia;
            this->inventario[pos].setPotenciaProduto(potencia);
            break;
    }
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
            int data_lacamento;
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
            cin >> data_lacamento;
            cin.ignore();
            cout << "Digite a potencia: ";
            cin >> potencia;
            ProdutoEletronico prod = ProdutoEletronico(id, nome, preco, qt_estoque, marca);
            Descricao desc = Descricao(peso, data_lacamento, potencia);
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
                menuAtualizarProduto();
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
