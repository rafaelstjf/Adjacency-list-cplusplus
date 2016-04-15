#include "iostream"
#include "ListaAdjacencia.h"
using namespace std;

ListaAdjacencia::ListaAdjacencia()//construtor
{
    prim = NULL;
    aux = NULL;
    tamanho = 0;
}
//navegacao
void ListaAdjacencia::inicio()
{
    aux = prim;
}
void ListaAdjacencia::proximoNo()//avanca o ponteiro aux ate o ultimo no
{
    if(aux != NULL)
    {
        aux = aux->consultarProxNo();
    }
}
bool ListaAdjacencia::existeIdNo(int id)
{
    inicio();
    while(aux->consultarId() != id)
    {
        proximoNo();
        if(aux == NULL)
        {
            return false;
        }
    }
    return true;
}
void ListaAdjacencia::procurarIdNo(int id)//procurar o no com o id desejado ateh o ultimo no, caso nao encontrado exibe mensagem de no inexistente
{
    inicio();
    while(aux->consultarId() != id)
    {
        proximoNo();
        if(aux==NULL)
        {
            cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
            break;
        }
    }

}
//manipulacao
void ListaAdjacencia::inserirUlt(int val) //insere um novo No no fim da lista
{
    if(prim == NULL)
    {
        No* c = new No();
        c->atribIdNo(val);
        c->atribProx(prim);
        c->atribAresta(NULL);
        prim = c;
        tamanho++;
    }
    else
    {
        inicio();
        while(aux->consultarProxNo() != NULL)
        {
            proximoNo();
        }
        No* c = new No();
        c->atribIdNo(val);
        c->atribProx(NULL);
        c->atribAresta(NULL);
        aux->atribProx(c);
        tamanho++;
    }
}
void ListaAdjacencia::adicionarAresta(int ini, int fim)//adiciona aresta
{
    if(existeIdNo(ini) && existeIdNo(fim))
    {
        procurarIdNo(ini);
        if(aux->consultarAresta() == NULL)//verifica se ja tem algum bloco no vertice
        {
            Bloco* f = new Bloco();
            f->atribId(fim);
            f->atribProx(NULL);
            aux->atribAresta(f);
        }
        else
        {
            Bloco* n = new Bloco();
            n = aux->consultarAresta();
            while(n->consultarProx() != NULL && fim != n->consultarId())//verifica se esta no ultimo bloco e se tem aresta repetida
            {
                n = n->consultarProx();

            }
            if(fim != n->consultarId())//verifica se o while foi parado por ter aresta repetida
            {
                Bloco* f = new Bloco();//adicionar novo bloco no final do anterior
                f->atribId(fim);
                f->atribProx(NULL);
                n->atribProx(f);
            }
            else
            {
                cout << "Aresta (" << ini <<", " << fim<<") ja existente!" << endl;
            }
        }
        cout << "Aresta (" << ini <<", " << fim<<") criada" <<endl;
    }
}
void ListaAdjacencia::imprimirLista() //imprime a lista
{
    inicio();
    Bloco* blocoAux = new Bloco();
    while(aux != NULL)
    {
        cout << "Vertice ID: " << aux->consultarId();
        if(aux->consultarAresta() != NULL)
        {
            blocoAux = aux->consultarAresta();
            while(blocoAux != NULL)
            {
                cout << "-> " << blocoAux->consultarId() << " ";
                blocoAux = blocoAux->consultarProx();
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
        procurarIdNo(id);
        Bloco* blocoAux = new Bloco();
        if(aux->consultarAresta() != NULL)
        {
            blocoAux = aux->consultarAresta();
            while(blocoAux != NULL)
            {
                grau++;
                blocoAux = blocoAux->consultarProx();
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
void ListaAdjacencia::preencherGrafoCompleto()
{
    for(int i=1; i<=tamanho; i++)
    {
        for(int j=1; j<=tamanho; j++)
        {
            if(j!=i)
            {
                adicionarAresta(i,j);

            }
        }
    }
}
ListaAdjacencia::~ListaAdjacencia()//destrutor
{
    No* p = prim;
    Bloco* baux1 = new Bloco();
    Bloco* baux2 = new Bloco();
    while(p != NULL)
    {
        No *t = p->consultarProxNo();
        if(p->consultarAresta()!=NULL)
        {
            baux1=p->consultarAresta();
            while(baux1!=NULL)
            {
                baux2 = baux1->consultarProx();
                delete baux1;
                baux1 = baux2;
            }
        }
        cout << "Vertice " << p->consultarId() <<" e suas arestas sendo apagado" << endl;
        delete p;
        p = t;

    }
    cout << "Grafo apagado!";
}
