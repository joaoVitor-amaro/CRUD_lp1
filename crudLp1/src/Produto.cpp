#include "Produto.h"
#include <iostream>
#include <string>
#include "ProdutoEletronico.h"
#include "Descricao.h"
#include "ProdutoCompleto.h"
#include "ItemIventario.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <iomanip>

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

void Produto::adcionarProduto(int id, int nome, float preco, int qt_estoque, int marca, float peso, int data_lacamento, float potencia){
    ProdutoEletronico prod = ProdutoEletronico(id, nome, preco, qt_estoque, marca);
    Descricao desc = Descricao(peso, data_lacamento, potencia);
    ProdutoCompleto prodCom = ProdutoCompleto(prod, desc);
    this->inventario.push_back(prodCom);
}

void Produto::listarProduto() {
    if(this->inventario.empty()) {
        cout << "Nenhum produto cadastrado" << endl;
    } else {
        cout << left << setw(5) << "ID" << left << setw(13) << "Nome"
        << left << setw(8) << "Preco" << left << setw(10) << "Estoque"
        << left << setw(10) << "Marca" << left << setw(10) << "Peso"
        << left << setw(15) << "Lancamento" << left << "Potencia" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        for(int i = 0; i < this->inventario.size(); i++) {
            this->inventario[i].exibirDados();
            cout << endl;
        }
        cout << "-------------------------------------------------------------------------------" << endl;
    }
}

void Produto::pesquisarProduto() {
    menuPesquisar();
    int idProduto;
    cout << "Id: ";
    cin >> idProduto;
    int i = buscarIdProduto(idProduto);//Busca o id do produto
    if(i >= 0) {
        dadosProdutospesqu(i); //Exibi os dados pesquisados do produto
    } else {
        cout << "Produto nao encontrado" << endl;
        sleep(0.8);
    }
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
    cout << "Informe o id para atualizar: ";
    cin >> id;
    system("cls");
    opcaoAtualizar();
    cout << "Digite a opcao para atualizar: ";
    cin >> opcao;
    system("cls");
    int pos = buscarIdProduto(id);
    if(pos >= 0) {
        atualizarProduto(opcao, pos);
    } else {
        cout << "Produto nao encontrado" << endl;
    }
}

void Produto::atualizarProduto(int opcao, int pos) {
    ProdutoEletronico prodEle;
    switch (opcao) {
        case 1:
            cout << "Nome do produto atual: " << this->inventario[pos].getNomeProduto() << endl;
            sleep(2);
            prodEle.menuProduto();
            int nome;
            cout << "Desejar atualizar para qual produto: ";
            cin >> nome;
            this->inventario[pos].setNomeProduto(nome);
            break;
        case 2:
            cout << "Preco do produto atual: R$" << this->inventario[pos].getPrecoProduto() << endl;
            float preco;
            cout << "Preco: ";
            cin >> preco;
            this->inventario[pos].setPrecoProduto(preco);
            break;
        case 3:
            cout << "Quantidade no estoque atual: " << this->inventario[pos].getQtEstoqueProduto() << endl;
            int qtd_estoque;
            cout << "Quantidade de Estoque: ";
            cin >> qtd_estoque;
            this->inventario[pos].setQtestoqueProduto(qtd_estoque);
            break;
        case 4:
            cout << "Marca atual do Produto: " << this->inventario[pos].getMarcaProduto() << endl;
            int marca;
            prodEle.menuMarca();
            cout << "Marca: ";
            cin >> marca;
            this->inventario[pos].setMarcaProduto(marca);
            break;
        case 5:
            cout << "Peso atual do produto: " << this->inventario[pos].getPesoProduto() << "g" << endl;
            float peso;
            cout << "Peso: ";
            cin >> peso;
            this->inventario[pos].setPesoProduto(peso);
            break;
        case 6:
            cout << "Ano lancamento atual: " << this->inventario[pos].getAnoLancamentoProduto() << endl;
            int ano_lancamento;
            cout << "Ano de lacamento: ";
            cin >> ano_lancamento;
            this->inventario[pos].setAno_lancamentoProduto(ano_lancamento);
            break;
        case 7:
            cout << "Potencia atual do Produto: " << this->inventario[pos].getPotenciaProduto() << "w" <<endl;
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
    cout << "Deletar Produto. id: ";
    cin >> idProdDeletar;
    int i = buscarIdProduto(idProdDeletar);
    if(i >= 0) {
        this->inventario.erase(this->inventario.begin() + i);
    } else {
        cout << "Produto não encontrado" << endl;
        sleep(2);
    }

}

int Produto::buscarIdProduto(int idProduto) {
    int identificador = 0;
    bool estado = false;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getIdProduto() == idProduto) {
            identificador = i;
            estado = true;
        }
    }
    if(estado) {
        return identificador;
    } else {
        return -1;
    }
}

void Produto::menuPesquisar() {
    cout << "===== Produto =====" << endl;
    for(int i = 0; i < this->inventario.size(); i++) {
        this->inventario[i].getIdNome();
    }
    cout << "-----------------------" << endl;
}

void Produto::dadosProdutospesqu(int i) {
    cout << left << setw(5) << "ID" << left << setw(13) << "Nome"
        << left << setw(8) << "Preco" << left << setw(10) << "Estoque"
        << left << setw(10) << "Marca" << left << setw(10) << "Peso"
        << left << setw(15) << "Lancamento" << left << "Potencia" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    this->inventario[i].exibirDados();
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

void Produto::adicionarDadosArquivos() {
    ofstream arquivo("dados.txt");
    if(arquivo.is_open()) {
        if(this->inventario.empty()) {
            return;
        } else {
            for(int i = 0; i < this->inventario.size(); i++) {
                arquivo << this->inventario[i].salvarDadosArquivos() << endl;
            }
            arquivo.close();
        }
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

int Produto::tipoNomeProduto(string nomeStr) {
    if (nomeStr == "Smartphone") {
        return 1;
    } else if (nomeStr == "Notebook") {
        return 2;
    } else if (nomeStr == "Tablet") {
        return 3;
    } else if (nomeStr == "Fone") {
        return 4;
    } else {
        return 0;
    }
}

int Produto::tipoMarcaProduto(string marcaStr) {
    if (marcaStr == "Samsung") {
        return 1;
    } else if (marcaStr == "Apple") {
        return 2;
    } else if (marcaStr == "Motorola") {
        return 3;
    } else if (marcaStr == "Nokia") {
        return 4;
    } else if (marcaStr == "Xiaomi") {
        return 5;
    } else {
        return 0;
    }
}

void Produto::lerArquivo() {
    ifstream arquivo("dados.txt");
    if(!arquivo.is_open()) {
        cout << "Erro ao ler o arquivo" << endl;
        return ;
    }
    string linha;
    while(getline(arquivo, linha)) {
        istringstream iss(linha);
        string idStr, nomeStr, precoStr, qt_estoqueStr, marcaStr, pesoStr, ano_lancaStr, potenciaStr;
        iss >> idStr >> nomeStr >> precoStr >> qt_estoqueStr >> marcaStr >> pesoStr >> ano_lancaStr >> potenciaStr;
        int id = stoi(idStr);
        int nome = tipoNomeProduto(nomeStr);
        float preco = stof(precoStr);
        int qt_estoque = stoi(qt_estoqueStr);
        int marca = tipoMarcaProduto(marcaStr);
        float peso = stof(pesoStr);
        int ano_lancamento = stoi(ano_lancaStr);
        float potencia = stof(potenciaStr);
        adcionarProduto(id, nome, preco, qt_estoque, marca, peso, ano_lancamento, potencia);
    }
}

int Produto::qtdEstoqueTotal() {
    int totalEstoque = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        totalEstoque += this->inventario[i].getQtEstoqueProduto();
    }
    return totalEstoque;
}

int Produto::qtdSmartphoneTotal() {
    int totalPhone = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getNomeProduto() == "Smartphone") {
            totalPhone++;
        }
    }
    return totalPhone;
}

int Produto::qtdNoteTotal() {
    int totalNote = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getNomeProduto() == "Notebook") {
            totalNote++;
        }
    }
    return totalNote;
}

int Produto::qtdTabletTotal() {
    int totalTablet = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getNomeProduto() == "Tablet") {
            totalTablet++;
        }
    }
    return totalTablet;
}

int Produto::qtdFoneTotal() {
    int totalFone = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getNomeProduto() == "Fone") {
            totalFone++;
        }
    }
    return totalFone;
}

int Produto::qtdSamsungTotal() {
    int totalSamsung = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getMarcaProduto() == "Samsung") {
            totalSamsung++;
        }
    }
    return totalSamsung;
}

int Produto::qtdAppleTotal() {
    int totalApple = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getMarcaProduto() == "Apple") {
            totalApple++;
        }
    }
    return totalApple;
}

int Produto::qtdMotorolaTotal() {
    int totalMoto = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getMarcaProduto() == "Motorola") {
            totalMoto++;
        }
    }
    return totalMoto;
}

int Produto::qtdNokiaTotal() {
    int totalNokia = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getMarcaProduto() == "Nokia") {
            totalNokia++;
        }
    }
    return totalNokia;
}

int Produto::qtdXiaomiTotal() {
    int totalXiaomi = 0;
    for(int i = 0; i < this->inventario.size(); i++) {
        if(this->inventario[i].getMarcaProduto() == "Xiaomi") {
            totalXiaomi++;
        }
    }
    return totalXiaomi;
}

void Produto::exibirRelatorio() {
    cout << "Quantidade total de Produto: " << qtdEstoqueTotal() << endl;
    cout << "Quantidade de Smartphone: " << qtdSmartphoneTotal() << endl;
    cout << "Quantidade de Notebook: " << qtdNoteTotal() << endl;
    cout << "Quantidade de Tablet: " << qtdTabletTotal() << endl;
    cout << "Quantidade de Fone: " << qtdFoneTotal() << endl;
    cout << "Quantidade de Samsung: " << qtdSamsungTotal() << endl;
    cout << "Quantidade de Apple: " << qtdAppleTotal() << endl;
    cout << "Quantidade de Motorola: " << qtdMotorolaTotal() << endl;
    cout << "Quantidade de Nokia: " << qtdNokiaTotal() << endl;
    cout << "Quantidade de Xiaomi: " << qtdXiaomiTotal() << endl;
}


void Produto::menu() {
    int opcao;
    lerArquivo();
    while(true) {
        menuOpcao();
        cout << "Opcao: ";
        cin >> opcao;
        system("cls");
        if(opcao == 7) {
            adicionarDadosArquivos();
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
            adcionarProduto(id, nome, preco, qt_estoque, marca, peso, data_lacamento, potencia);
        } else if(opcao == 2) {
            listarProduto();
            sleep(5);
        } else if(opcao == 3) {
            if(this->inventario.empty()) {
                cout << "Nenhum produto cadastrado" << endl;
                sleep(2);
            } else {
                pesquisarProduto();
                sleep(3);
            }
        } else if(opcao == 4) {
            if(this->inventario.empty()) {
                cout << "Sem Produtos" << endl;
                sleep(2);
            } else {
                menuAtualizarProduto();
            }
        } else if(opcao == 5) {
            if(this->inventario.empty()) {
                cout << "Sem produtos" << endl;
                sleep(2);
            } else {
                deletarProduto();
            }
        } else if(opcao == 6) {
            cout << "Relatorio" << endl;
            cout << "-=-=-=-=-" << endl;
            exibirRelatorio();
            sleep(5);
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
            sleep(0.5);
        }
        system("cls");

    }
}
