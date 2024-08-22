#include "Descricao.h"

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
   this->fabrincante = fabricante;
}
void Descricao::setpotencia(){
 this->potencia=potencia;
}
