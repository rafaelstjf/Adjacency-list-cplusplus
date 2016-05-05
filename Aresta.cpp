
#include "Aresta.h"

Aresta::Aresta()//construtor da classe
{
    proximo = NULL;
    id = 0;
	anterior = NULL;
}
int Aresta::getId()//retorna o ID do Aresta
{
    return id;

}
Aresta* Aresta::getProx()//consulta o proximo Aresta
{
    return proximo;
}
void Aresta::setId(int val)//atribui um novo valor para o ID
{
    id = val;
}
void Aresta::setProx(Aresta* p)//atribui um novo Aresta para o ponteiro proximo
{
    proximo = p;
}
Aresta* Aresta::getAnterior()
{
    return anterior;
}
void Aresta::setAnterior(Aresta* c)
{
    anterior = c;
}
Aresta::~Aresta() {} //destrutor da classe
