#include "iostream"
#include "ListaAdjacencia.h"
using namespace std;

ListaAdjacencia::ListaAdjacencia(bool tipo)//construtor
{
    prim = NULL;
    aux = NULL;
    orientada = tipo;
    tamanho = 0;
}
//navegacao
void ListaAdjacencia::inicio()//coloca o ponteiro auxiliar apontando para o primeiro No da lista
{
    aux = prim;
}
void ListaAdjacencia::proximoNo()//avanca o ponteiro auxiliar ate o ultimo No
{
    if(aux != NULL)
    {
        aux = aux->consultarProxNo();
    }
}
bool ListaAdjacencia::ListaVazia()//verifica se a lista esta vazia
{
    if(prim == NULL)
        return true;
    else return false;
}
bool ListaAdjacencia::existeIdNo(int id)//verifica se existe o No do id desejado
{

    if(!ListaVazia())
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
    else return false;

}
void ListaAdjacencia::procurarIdNo(int id)//faz o ponteiro auxiliar apontar para o No de id desejado
{

    if(!ListaVazia())
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
    else
        cout << "Lista vazia!" << endl;

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
Bloco* ListaAdjacencia::criarBloco(int id, Bloco* prox)//cria um novo bloco
{
    Bloco* b = new Bloco();
    b->atribId(id);
    b->atribProx(prox);
    return b;
}
void ListaAdjacencia::adicionarArco(int ini, int fim)//adiciona um novo arco
{
    procurarIdNo(ini);
    if(aux->consultarAresta() == NULL)//verifica se ja tem algum bloco no vertice
    {
        aux->atribAresta(criarBloco(fim, NULL));
        aux->atribGrauNo(aux->consultarGrauNo() + 1);//aumenta o grau do No
    }
    else
    {
        Bloco* n;
        n = aux->consultarAresta();
        while(n->consultarProx() != NULL && fim != n->consultarId())//verifica se esta no ultimo bloco e se tem aresta repetida
        {
            n = n->consultarProx();

        }
        if(fim != n->consultarId())//verifica se o while foi parado por ter aresta repetida
        {
            n->atribProx(criarBloco(fim, NULL));
            aux->atribGrauNo(aux->consultarGrauNo() + 1);
        }
        else
        {
            if(orientada)
                cout << "Arco (" << ini <<", " << fim<<") ja existente!" << endl;
        }
    }
}
void ListaAdjacencia::adicionarAresta(int ini, int fim)//verifica o tipo de grafo e adiciona uma aresta/arco
{
    if(existeIdNo(ini) && existeIdNo(fim))
    {
        if(orientada)
            adicionarArco(ini, fim);
        else
        {
            adicionarArco(ini,fim);
            adicionarArco(fim, ini);
        }
    }

}
int ListaAdjacencia::calcGrauNo(int id)
{
    if(existeIdNo(id))//verifica se existe o no de ID desejado
    {
        procurarIdNo(id);
        return aux->consultarGrauNo();
    }
    else//caso nao encontre o no, exibe mensagem de erro e retorna o grau como 0
    {
        cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
        return -1;
    }

}
void ListaAdjacencia::preencherGrafoCompleto()//preenche todas as arestas de maneira a criar o grafo completo
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
int ListaAdjacencia::calcGrauGrafo()//calcula o grau do grafo; Grau do grafo = grau do maior no
{
    int grauGrafo = -1;
    for(int i = 0; i<tamanho; i++)
    {
        if(grauGrafo <=calcGrauNo(i+1))
        {
            grauGrafo  = calcGrauNo(i+1);
        }
    }
    return grauGrafo;
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
