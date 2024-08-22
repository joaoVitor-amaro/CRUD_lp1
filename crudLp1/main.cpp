#include <iostream>
#include "ItemIventario.h"
#include "Descricao.h"
#include "ProdutoEletronico.h"
using namespace std;

int main(){
    Descricao d;
    ProdutoEletronico pe;
    pe.leratributos();
    d.leratributos();
    cout << d.getdatadelancamento() << endl;
    cout << pe.getCategoria() << endl;
    cout << pe.getNome() << endl;
    return 0;
}
