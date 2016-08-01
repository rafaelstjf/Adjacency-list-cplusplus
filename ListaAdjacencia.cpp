#include "ListaAdjacencia.h"

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
        if(aux!= NULL && aux->getId() == id)
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
void ListaAdjacencia::inserir(int val, int peso)
{
    Aresta* c = new Aresta();
    c->setId(val);
    c->setPeso(peso);
    if(pri == NULL)
    {
        c->setProx(pri);
        c->setAnterior(NULL);
        pri = c;
        ult = c;
    }
    else
    {
        if(val < ult->getId())
        {
            inicio();
            while(aux->getProx() != NULL && aux->getId() < val)
                proximaAresta();
            if(aux == pri)
            {
                c->setAnterior(NULL);
                c->setProx(aux);
                pri = c;
            }
            else
            {
                c->setAnterior(aux->getAnterior());
                c->setProx(aux);
                Aresta* aux2 = aux->getAnterior();
                aux2->setProx(c);
                aux->setAnterior(c);
            }
        }
        else
        {
            c->setProx(NULL);
            c->setAnterior(ult);
            ult->setProx(c);
            ult = c;
        }
    }
}
void ListaAdjacencia::removerAresta(int id)
{
    Aresta* a = NULL;
    if(existeIdAresta(id))
    {
        inicio();
        procurarIdAresta(id);
        a = aux;
        if(aux == pri && aux !=ult)
        {
            pri = aux->getProx();
            pri->setAnterior(NULL);
        }
        else if(aux ==ult && aux!=pri)
        {
            a = aux;
            aux = aux->getAnterior();
            aux->setProx(NULL);
            ult = aux;

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
            aux = a->getAnterior();
            aux->setProx(a->getProx());
            Aresta* aux2 = a->getProx();
            aux2->setAnterior(aux);

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
