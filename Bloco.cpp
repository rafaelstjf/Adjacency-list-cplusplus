#include <iostream>
#include "Bloco.h"
using namespace std;

Bloco::Bloco()//construtor da classe
{
    proximo = NULL;
}
int Bloco::consultarId()//consultarr o ID do bloco
{
    return id;

}
Bloco* Bloco::consultarProx()//consultar o proximo bloco
{
    return proximo;
}
void Bloco::atribId(int val)//atribui um novo valor para o ID
{
    id = val;
}
void Bloco::atribProx(Bloco* p)//atribui um novo bloco para o ponteiro proximo
{
    proximo = p;
}
Bloco::~Bloco() {} //destrutor da classe
