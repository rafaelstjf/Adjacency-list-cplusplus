#include <iostream>
#include "No.h"
using namespace std;

No::No()//construtor da classe
{
    proxNo = NULL;
    antNo = NULL;
    arestas = NULL;
    grauNo = 0;
    idNo = 0;
    visitado = false;
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
void No::setAntNo(No* a){
antNo = a;
}
void No::setVisitado(bool estado){
visitado = estado;
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
No* No::getAntNo(){
return antNo;
}
bool No::getVisitado(){
return visitado;
}
int No::getGrauNo(){
return grauNo;
}
No::~No() {}//destrutor da classe
