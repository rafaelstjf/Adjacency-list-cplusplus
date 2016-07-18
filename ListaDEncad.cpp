#include "ListaDEncad.h"
using namespace std;
ListaDEncad::ListaDEncad()//construtor
{
    pri = NULL;
    it = NULL;
    ult = NULL;
    tamanho = 0;
    semente = 0;
    alfa  = 0.0;
}
void ListaDEncad::inicio()
{
    it = pri;
}
void ListaDEncad::proxBloco()
{
    if(it != NULL)
        it = it->getProximo();
}
bool ListaDEncad::listaVazia()
{
    if(pri == NULL)
        return true;
    else return false;
}
void ListaDEncad::inserirOrdGrau(int id, int grau)
{
    Bloco* c = new Bloco();
    c->setId(id);
    c->setGrau(grau);
    if(pri == NULL)
    {
        c->setProximo(pri);
        c->setAnterior(NULL);
        pri = c;
        ult = c;
    }
    else
    {
        if(grau < ult->getGrau())
        {
            inicio();
            while(it->getProximo() != NULL && it->getGrau() < grau)
            {
                proxBloco();
            }
            if(it == pri)
            {
                c->setAnterior(NULL);
                c->setProximo(it);
                it->setAnterior(c);
                pri = c;
            }
            else
            {
                c->setAnterior(it->getAnterior());
                c->setProximo(it);
                Bloco* it2 = it->getAnterior();
                it2->setProximo(c);
                it->setAnterior(c);
            }
        }
        else
        {
            c->setProximo(NULL);
            c->setAnterior(ult);
            ult->setProximo(c);
            ult = c;
        }
    }
    tamanho++;
}

Bloco* ListaDEncad::getIt()
{
    return it;
}
bool ListaDEncad::existeId(int id)
{

    if(!listaVazia())
    {
        inicio();
        while(it!=NULL)
        {
            if(it->getId() == id)
            {
                return true;
                break;
            }
            proxBloco();
        }
        return false;
    }
    else return false;
}
void ListaDEncad::procurarId(int id)
{
    inicio();
    while(it!=NULL)
    {
        if(it->getId() == id)
            break;
        proxBloco();
    }
}
void ListaDEncad::removerId(int id)
{
    Bloco* b = NULL;
    if(existeId(id))
    {
        procurarId(id);
        b = it;
        if(it == pri && it !=ult)
        {
            pri = it->getProximo();
            pri->setAnterior(NULL);
        }
        else if(it ==ult && it!=pri)
        {
            b = it;
            it = it->getAnterior();
            it->setProximo(NULL);
            ult = it;

        }
        else if(it == pri && it == ult)
        {
            b = it;
            pri = NULL;
            ult = NULL;
        }
        else if(it!= pri && it != ult)
        {
            b = it;
            it = b->getAnterior();
            it->setProximo(b->getProximo());
            Bloco* aux = b->getProximo();
            aux->setAnterior(it);

        }
        delete b;
        tamanho--;
    }
}
int ListaDEncad::getTamanho()
{
    return tamanho;
}
int ListaDEncad::getSemente(){
return semente;
}
void ListaDEncad::setSemente(int s){
semente = s;
}
void ListaDEncad::setAlfa(double a){
alfa  = a;
}
double ListaDEncad::getAlfa(){
return alfa;
}
ListaDEncad::~ListaDEncad()
{
    Bloco* p = pri;
    while(p != NULL)
    {
        Bloco *t = p->getProximo();
        delete p;
        p = t;
    }
}
