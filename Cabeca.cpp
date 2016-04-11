#include <iostream>
#include "Cabeca.h"
using namespace std;

Cabeca::Cabeca()//construtor da classe
{
    proxCabeca = NULL;
    ligacao = NULL;
}
void Cabeca::atribIdCabeca(int p)
{
    idCabeca = p;
}
void Cabeca::atribLigacao(No* p)
{
    ligacao = p;
}
void Cabeca::atribProx(Cabeca* c)
{
    proxCabeca = c;
}
int Cabeca::consultaId()
{
    return idCabeca;
}
No* Cabeca::consultaLigacao()
{
    return ligacao;
}
Cabeca* Cabeca::consultaProxCabeca()
{
    return proxCabeca;
}
Cabeca::~Cabeca() {}//destrutor da classe
