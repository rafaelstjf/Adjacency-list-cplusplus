#include "iostream"
#include "ListaAdjacencia.h"

using namespace std;
ListaAdjacencia::ListaAdjacencia()//construtor
{
    prim = NULL;
    aux = NULL;
}
//navegacao
void ListaAdjacencia::inicio()
{
    aux = prim;
}
void ListaAdjacencia::proximoNo()//avanca o ponteiro aux ate o ultimo no
{
    if(aux->consultaProxNo()!= NULL)
    {
        aux = aux->consultaProxNo();
    }
}
void ListaAdjacencia::procuraIdNo(int id)//procura o no com o id desejado ateh o ultimo no, caso nao encontrado exibe mensagem de no inexistente
{
    inicio();
    if(existeIdNo(id))
    {
        while(aux->consultaId() != id)
        {
            proximoNo();
        }
    }
    else
    {
        cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
    }
}
bool ListaAdjacencia::existeIdNo(int id)
{
    inicio();
    while(aux->consultaId() != id)
    {
        proximoNo();
        if(aux->consultaProxNo() == NULL)
        {
            return false;
        }
    }
    return true;
}
//insercao
void ListaAdjacencia::inserePri(int val) //insere um novo No no inicio
{
    No* c = new No();
    c->atribIdNo(val);
    c->atribProx(prim);
    c->atribAresta(NULL);
    prim = c;
}
void ListaAdjacencia::insereUlt(int val) //insere um novo No no fim da lista
{
    inicio();

    if(prim == NULL)
    {
        inserePri(val);
    }
    else
    {
        while(aux->consultaProxNo() != NULL)
        {
            proximoNo();
        }
        No* c = new No();
        c->atribIdNo(val);
        c->atribProx(NULL);
        c->atribAresta(NULL);
        aux->atribProx(c);

    }

}
void ListaAdjacencia::adicionaAresta(int ini, int fim)//adiciona aresta
{
    inicio();
    procuraIdNo(ini);
    if(aux->consultaAresta() != NULL)//verifica se ja tem algum bloco no vertice
    {
        Bloco* n = new Bloco();
        n = aux->consultaAresta();
        while(n->consultaProx() != NULL)//adiciona novo bloco no final do anterior
        {
            n = aux->consultaAresta()->consultaProx();
        }
        Bloco* f = new Bloco();
        f->atribId(fim);
        f->atribProx(NULL);
        n->atribProx(f);
    }
    else
    {
        Bloco* f = new Bloco();
        f->atribId(fim);
        f->atribProx(NULL);
        aux->atribAresta(f);
    }


}

void ListaAdjacencia::imprimeLista()
{
    inicio();
    Bloco* blocoAux = new Bloco();
    while(aux->consultaProxNo() != NULL)
    {
        cout << "Vertice ID: " << aux->consultaId();
        if(aux->consultaAresta() != NULL)
        {
            blocoAux = aux->consultaAresta();
            while(blocoAux != NULL)
            {
                cout << " -> " << blocoAux->consultaId() << " ";
                blocoAux = blocoAux->consultaProx();
            }

        }
        cout << endl;
        proximoNo();
    }
}
int ListaAdjacencia::calcGrauNo(int id)
{
    int grau=0;
    if(existeIdNo(id))//verifica se existe o no de ID desejado
    {
        procuraIdNo(id);
        Bloco* blocoAux = new Bloco();
        if(aux->consultaAresta() != NULL)
        {
            blocoAux = aux->consultaAresta();
            while(blocoAux != NULL)
            {
                grau++;
                blocoAux = blocoAux->consultaProx();
            }

        }
        return grau;
    }
    else//caso nao encontre o no, exibe mensagem de erro e retorna o grau como 0
    {
        cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
        grau = -1;
        return grau;
    }

}
