#include <iostream>
#include <stdlib.h>
#include "TListaSEncad.h"
using namespace std;
// operações normais
TListaSEncad::TListaSEncad() //construtor
{
    it = NULL;
    pri = NULL;
}
float TListaSEncad::Consulta() //consulta o valor do No apontado por it
{
    if(it != NULL)
        return it->consultaInfo();
    else
    {
        cout << "Erro: No Invalido!" << endl;
        exit(1);
    }
}
void TListaSEncad::Atribui(float val) //atribui um valor no No apontado por it
{
    if(it != NULL)
        it->atribInfo(val);

    else
        {
            if(pri == NULL)
                cout << "Erro: No invalido!" << endl;
        }
}
bool TListaSEncad::Busca(float val) //Busca um No na lista
{
    No *p;
    for(p = pri; p != NULL; p = p->consultaProx())
    {
        if(p->consultaInfo() == val)
            return true;
    }
    return false;
}
//operações para percorrer a lista
void TListaSEncad::Inicio() //coloca it apontando para o inicio da lista
{
    it = pri;
}
void TListaSEncad::ProximoNo() //coloca it apontando para o "consultaProx" do No atual
{
   if(it!= NULL)
   {
            it = it->consultaProx();

   }
   else
   {
       cout << "Erro. Nao ha proximos Nos" <<endl;
   }
}
bool TListaSEncad::FimDaLista() //coloca it apontando para NULL
{
    if(it == NULL)
        return true;
    else
        return false;
}
TListaSEncad::~TListaSEncad() //Destrutor
{
    No* p = pri;
    while(p != NULL)
    {
        No *t = p->consultaProx();
        delete p;
        p = t;
    }
}
void TListaSEncad::InserePri(float val) //insere um novo No no inicio
{
    No* p = new No();
    p->atribInfo(val);
    p->atribProx(pri);
    pri = p;
}
void TListaSEncad::InsereK(float val) //insere um No antes do No apontado por it
{
    if(it != NULL)
    {
        No* p = it;
        Inicio();
        if(pri != p)
        {
            while(it->consultaProx() != p )
            {
                ProximoNo();
            }
            No* t = new No();
            t->atribInfo(val);
            t->atribProx(p);
            it->atribProx(t);
        }
        else
        {
            InserePri(val);
        }
    }
    else
    {   if(pri == NULL)
            cout << "Erro. Lista Vazia!" << endl;
    }

}
void TListaSEncad::InsereUltimo(float val) //insere um novo No no fim da lista
{
    Inicio();
    while(it->consultaProx() != NULL)
    {
        ProximoNo();
    }
    No* p = new No();
    p->atribInfo(val);
    p->atribProx(NULL);
    it->atribProx(p);

}
void TListaSEncad::EliminaPri() //elimina o primeiro no
{
    No* p;
    if(pri != NULL)
    {
        if(pri == it)
            it = pri->consultaProx();
        p = pri;
        pri = p->consultaProx();
        delete p;
    }
    else
    {
        cout << "Erro. Lista Vazia!" << endl;
        exit(1);
    }
}
void TListaSEncad::EliminaK()
{
    if(pri == NULL)
    {
        cout << "Erro. Lista Vazia!" << endl;
        exit(1);
    }
    else
    {
        No* p = it;
        Inicio();
        while(it->consultaProx() != p)
        {
            ProximoNo();
        }
        it->atribProx(p->consultaProx());
    }
}
void TListaSEncad::EliminaUltimo()
{
    if (pri == NULL)
    {
        cout << "Erro. Lista Vazia!" << endl;
        exit(1);
    }
    else
    {
        Inicio();
        No* p = it;
        while(it->consultaProx() != NULL)
        {

            if(p->consultaProx()!=NULL)
            {
                p = it;
                ProximoNo();
            }

        }
        p->atribProx(NULL);
    }
}
