#include "Descricao.h"
#include <string>
#include "ProdutoEletronico.h"
using namespace std ;

Descricao::Descricao()
{

}
Descricao::Descricao(float peso, string data_de_lancamento, string fabricante, float potencia){
    this->potencia = potencia;
    this->peso=peso;
    this->data_de_lancamento=data_de_lancamento;
    this->fabricante=fabricante;
}

//get
float Descricao::getpeso(){
   return this->peso;
}
string Descricao::getdatadelancamento(){
 return this->data_de_lancamento;
}
string Descricao::getfabricante(){
 return this->fabricante;
}
float Descricao::getpotencia(){
   return this->potencia;
}


//set
void Descricao::setpeso(float peso){
    this->peso = peso;
}
void Descricao::setdatadelancamento(string data_de_lancamento){
  this->data_de_lancamento = data_de_lancamento;
}
void Descricao::setfabricante(string fabricante){
   this->fabricante = fabricante;
}
void Descricao::setpotencia(float potencia){
 this->potencia=potencia;
}

void Descricao::leratributos() {
    cout << "Digite o peso: ";
    cin >> this->peso;
    cin.ignore();
    cout << "Digite a data de lancamento: ";
    getline(cin, this->data_de_lancamento);
    cout << "Digite o fabricante: ";
    getline(cin, this->fabricante);
    cout << "Digite a potencia: ";
    cin >> this->potencia;

    }
