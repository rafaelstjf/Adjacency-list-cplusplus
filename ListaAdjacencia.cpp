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
        procurarIdAresta(id);
        if(aux!= NULL && aux->getId())
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

}
//manipulacao
void ListaAdjacencia::inserir(int val)
{
    Aresta* c = new Aresta();
    if(pri == NULL)
    {

        c->setId(val);
        c->setProx(pri);
        c->setAnterior(NULL);
        pri = c;
        ult = c;
    }
    else
    {
        inicio();
        while(aux->getProx() != NULL && aux->getId() != val)
        {
            proximaAresta();
        }
            if(aux->getId() == val)
                cout << "ja existe esta aresta" << endl;
            else
            {
                c->setId(val);
                c->setProx(NULL);
                c->setAnterior(aux);
                aux->setProx(c);
                ult = c;
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
void ListaAdjacencia::removerAresta(int id)
{
    Aresta* a = NULL;
    if(existeIdAresta(id))
    {
        inicio();
        procurarIdAresta(id);
        if(aux == pri && aux !=ult)
        {
            pri = aux->getProx();
            pri->setAnterior(NULL);
            delete aux;

        }
        else if(aux ==ult && aux!=pri)
        {
            a = aux;
            aux = aux->getAnterior();
            aux->setProx(NULL);
            ult = aux;
            delete a;

        }
        else if(aux == pri && aux == ult)
        {
            a = aux;
            pri = NULL;
            ult = NULL;
        }
        else if(aux!= pri && aux != ult)
        {
            a = aux;
            aux = aux->getAnterior();
            aux->setProx(a->getProx());
        }
        delete a;
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
