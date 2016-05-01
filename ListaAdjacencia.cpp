#include "iostream"
#include "ListaAdjacencia.h"
using namespace std;

ListaAdjacencia::ListaAdjacencia()//construtor
{
    pri = NULL;
    aux = NULL;
    ult = NULL;
}
//navegacao
void ListaAdjacencia::inicio()
{
    aux = pri;
}
void ListaAdjacencia::proximaAresta()
{
    if(aux != NULL)
    {
        aux = aux->getProx();
    }
}
bool ListaAdjacencia::listaVazia()
{
    if(pri == NULL)
        return true;
    else return false;
}
bool ListaAdjacencia::existeIdAresta(int id)
{

    if(!listaVazia())
    {
        if(id>=pri->getId() && id <=ult->getId() )
            return true;
        else
            return false;
    }
    else return false;

}
Aresta* ListaAdjacencia::getAux()
{
    return aux;
}
void ListaAdjacencia::procurarIdAresta(int id)
{

    if(!listaVazia())
    {
        inicio();
        while(aux->getId() != id)
        {
            proximaAresta();
            if(aux==NULL)
            {
                break;
            }
        }
    }
    else
        cout << "Lista vazia!" << endl;

}
//manipulacao
void ListaAdjacencia::inserir(int val)
{
    if(pri == NULL)
    {
        Aresta* c = new Aresta();
        c->setId(val);
        c->setProx(pri);
        c->setAnterior(NULL);
        pri = c;
        ult = c;
    }
    else
    {
        inicio();
        while(aux->getProx() != NULL && aux->getId() <= val)
        {
            proximaAresta();
        }
        if(aux->getId() <= val)
        {
            if(aux->getId() == val)
                cout << "ja existe esta aresta" << endl;
            else
            {
                Aresta* c = new Aresta();
                c->setId(val);
                c->setProx(NULL);
                c->setAnterior(aux);
                aux->setProx(c);
                ult = c;
            }
        }
        else
        {
            Aresta* c = new Aresta();
            c->setId(val);
            c->setProx(aux);
            c->setAnterior(aux->getAnterior());
            aux->setAnterior(c);
        }
    }
}
void ListaAdjacencia::imprimir()
{
    inicio();
    while(aux != NULL)
    {
        cout << "-> " << aux->getId() << " ";
        proximaAresta();
    }

}

ListaAdjacencia::~ListaAdjacencia()//destrutor
{
    Aresta* p = pri;
    while(p != NULL)
    {
        Aresta *t = p->getProx();
        delete p;
        p = t;
    }
}
