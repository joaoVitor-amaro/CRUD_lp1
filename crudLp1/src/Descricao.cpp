#include "Descricao.h"
#include <string>
#include "ProdutoEletronico.h"
#include <iomanip>

using namespace std ;

Descricao::Descricao(){}

Descricao::Descricao(float peso, int data_de_lancamento, float potencia){
    this->potencia = potencia;
    this->peso=peso;
    this->data_de_lancamento=data_de_lancamento;
}

//get
float Descricao::getpeso(){
   return this->peso;
}
int Descricao::getdatadelancamento(){
 return this->data_de_lancamento;
}
float Descricao::getpotencia(){
   return this->potencia;
}

//set
void Descricao::setpeso(float peso){
    this->peso = peso;
}
void Descricao::setdatadelancamento(int data_de_lancamento){
  this->data_de_lancamento = data_de_lancamento;
}
void Descricao::setpotencia(float potencia){
 this->potencia=potencia;
}

void Descricao::exibirDados() {
    cout << this->peso << left << setw(9) << "g";
    cout << left << setw(15) << this->data_de_lancamento;
    cout << this->potencia << "w";
}
