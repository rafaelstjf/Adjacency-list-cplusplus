#include <iostream>
#include "No.h"
using namespace std;

No::No() {
proximo = NULL;
} //construtor da classe
int No::consultaId()//consulta o ID do no
{
    return id;

}
No* No::consultaProx()//consulta o proximo no
{
    return proximo;
}
void No::atribId(int val)//atribui um novo valor para o ID
{
    id = val;
}
void No::atribProx(No* p)//atribui um novo no para o ponteiro proximo
{
    proximo = p;
}
No::~No() {} //destrutor da classe
