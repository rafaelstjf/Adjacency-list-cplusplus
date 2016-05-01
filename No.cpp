#include <iostream>
#include "No.h"
using namespace std;

No::No()//construtor da classe
{
    proxNo = NULL;
    arestas = NULL;
    grauNo = 0;
    }
void No::setIdNo(int p)
{
    idNo = p;
}
void No::setArestas(ListaAdjacencia* p)
{
    arestas = p;
}
void No::setProx(No* c)
{
    proxNo = c;
}
void No::setGrauNo(int grau){
grauNo = grau;
}
int No::getId()
{
    return idNo;
}
ListaAdjacencia* No::getArestas()
{
    return arestas;
}
No* No::getProxNo()
{
    return proxNo;
}
int No::getGrauNo(){
return grauNo;
}
No::~No() {}//destrutor da classe
