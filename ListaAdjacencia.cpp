#include "iostream"
#include "ListaAdjacencia.h"

using namespace std;
ListaAdjacencia::ListaAdjacencia()
{
    prim = NULL;
    aux = NULL;
}
//navegacao
void ListaAdjacencia::inicio()
{
    aux = prim;
}
void ListaAdjacencia::proximaCabeca()
{
    if(aux!= NULL)
    {
        aux = aux->consultaProxCabeca();
    }
    else
    {
        cout << "Erro. Nao ha proxima cabeca" <<endl;
    }
}
//insercao
void ListaAdjacencia::inserePri(int val) //insere uma nova Cabeca no inicio
{
    Cabeca* c = new Cabeca();
    c->atribIdCabeca(val);
    c->atribProx(prim);
    c->atribLigacao(NULL);
    prim = c;
}
void ListaAdjacencia::insereUlt(int val) //insere uma nova Cabeca no fim da lista
{
    inicio();
    if(prim == NULL)
    {
        inserePri(val);
    }
    else
    {
        while(aux->consultaProxCabeca() != NULL)
        {
            proximaCabeca();
        }
        Cabeca* c = new Cabeca();
        c->atribIdCabeca(val);
        c->atribProx(NULL);
        c->atribLigacao(NULL);
        aux->atribProx(c);

    }

}
void ListaAdjacencia::adicionarLigacao(int ini, int fim)
{
    inicio();
    while(aux->consultaId() != ini)
    {
        proximaCabeca();
    }
    if(aux->consultaLigacao() != NULL)
    {
        No* n = new No();
        n = aux->consultaLigacao();
        while(n->consultaProx() != NULL)
        {
            n = aux->consultaLigacao()->consultaProx();
        }
        No* f = new No();
        f->atribId(fim);
        f->atribProx(NULL);
        n->atribProx(f);
    }
    else
    {
        No* f = new No();
        f->atribId(fim);
        f->atribProx(NULL);
        aux->atribLigacao(f);
    }


}

void ListaAdjacencia::imprimeLista()
{
    inicio();
    No* noaux = new No();
    while(aux->consultaProxCabeca() != NULL)
    {
        cout << "Vertice ID: " << aux->consultaId();
        if(aux->consultaLigacao() != NULL)
        {
            noaux = aux->consultaLigacao();
            while(noaux != NULL)
            {
                cout << " -> " << noaux->consultaId() << " ";
                noaux = noaux->consultaProx();
            }

        }
        cout << endl;
        proximaCabeca();


    }
}
