#include "Bloco.h"
using namespace std;
Bloco::Bloco()
{
    anterior = NULL;
    proximo = NULL;
    id = 0;
    grau = 0;
}
void Bloco::setId(int i)
{
    id = i;
}
void Bloco::setGrau(int g)
{
    grau = g;
}
void Bloco::setAnterior(Bloco* a)
{
    anterior = a;
}
void Bloco::setProximo(Bloco* p)
{
    proximo = p;
}
int Bloco::getId()
{
    return id;
}
int Bloco::getGrau()
{
    return grau;
}
Bloco* Bloco::getAnterior()
{
    return anterior;
}
Bloco* Bloco::getProximo()
{
    return proximo;
}
Bloco::~Bloco()
{
}
