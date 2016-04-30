#include <iostream>
#include "No.h"
using namespace std;

No::No()//construtor da classe
{
    proxNo = NULL;
    aresta = NULL;
    grauNo = 0;
    }
void No::atribIdNo(int p)
{
    idNo = p;
}
void No::atribAresta(Bloco* p)
{
    aresta = p;
}
void No::atribProx(No* c)
{
    proxNo = c;
}
void No::atribGrauNo(int grau){
grauNo = grau;
}
int No::consultarId()
{
    return idNo;
}
Bloco* No::consultarAresta()
{
    return aresta;
}
No* No::consultarProxNo()
{
    return proxNo;
}
int No::consultarGrauNo(){
return grauNo;
}
No::~No() {}//destrutor da classe
