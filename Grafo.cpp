#include <iostream>
#include <stack>
#include "Grafo.h"
using namespace std;

Grafo::Grafo(bool tipo)//construtor
{
    prim = NULL;
    aux = NULL;
    orientada = tipo;
    tamanho = 0;
}
//navegacao
void Grafo::inicio()//coloca o ponteiro auxiliar apontando para o primeiro No da lista
{
    aux = prim;
}
void Grafo::proximoNo()//avanca o ponteiro auxiliar ate o ultimo No
{
    if(aux != NULL)
        aux = aux->consultarProxNo();
}
bool Grafo::listaVazia()//verifica se a lista esta vazia
{
    if(prim == NULL)
        return true;
    else return false;
}
bool Grafo::existeIdNo(int id)//verifica se existe o No do id desejado
{
    if(!listaVazia())
    {
        inicio();
        while(aux->consultarId() != id)
        {
            proximoNo();
            if(aux == NULL)
            {
                cout << "No Id:" << id << " nao existe!" << endl;
                return false;
            }
        }
        return true;
    }
    else return false;

}
void Grafo::procurarIdNo(int id)//faz o ponteiro auxiliar apontar para o No de id desejado
{
    if(!listaVazia())
    {
        inicio();
        while(aux->consultarId() != id)
        {
            proximoNo();
            if(aux==NULL)
                break;
        }
    }
}
//manipulacao
void Grafo::inserirNo(int val) //insere um novo No no fim da lista
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
Bloco* Grafo::criarBloco(int id, Bloco* prox)//cria um novo bloco
{
    Bloco* b = new Bloco();
    b->atribId(id);
    b->atribProx(prox);
    return b;
}
void Grafo::adicionar(int ini, int fim)//adiciona um novo arco
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
void Grafo::adicionarAresta(int ini, int fim)//verifica o tipo de grafo e adiciona uma aresta/arco
{
    if(existeIdNo(ini) && existeIdNo(fim) && ini!=fim)
    {
        if(orientada)
            adicionar(ini, fim);
        else
        {
            adicionar(ini,fim);
            adicionar(fim, ini);
        }
    }
}
int Grafo::grauNo(int id)
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
int Grafo::grauGrafo()//calcula o grau do grafo; Grau do grafo = grau do maior no
{
    int grauGrafo = -1;
    for(int i = 0; i<tamanho; i++)
    {
        if(grauGrafo <=grauNo(i+1))
        {
            grauGrafo  = grauNo(i+1);
        }
    }
    return grauGrafo;
}
bool Grafo::verificarAdjacencia(int id1, int id2)//verifica se existe uma aresta ligando os dois Nos desejados
{
    if(existeIdNo(id1) && existeIdNo(id2))
    {
        procurarIdNo(id1);
        if(aux->consultarAresta() != NULL)
        {
            Bloco* n;
            n = aux->consultarAresta();
            while(n->consultarProx() != NULL && id2 != n->consultarId())//verifica se esta no ultimo bloco e se tem aresta repetida
            {
                n = n->consultarProx();
            }
            if(id2 != n->consultarId())//verifica se o while foi parado por ter aresta repetida
                return true;
        }
        else
            return false;
    }
    else
        return false;
}
void Grafo::listarAdjacentesNo(int id)//imprime os adjacentes do No de Id desejado
{
    if(existeIdNo(id))
    {
        procurarIdNo(id);
        Bloco* blocoAux;
        cout << "No ID: " << aux->consultarId();
        if(aux->consultarAresta() != NULL)
        {
            blocoAux = aux->consultarAresta();
            while(blocoAux != NULL)
            {
                cout << "-> " << blocoAux->consultarId() << " ";
                blocoAux = blocoAux->consultarProx();
            }
            cout << endl;
        }
    }
    else
        cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
}
int Grafo::verificarKRegular()
{
    if(!listaVazia())
    {
        inicio();
        int k = aux->consultarGrauNo();
        while(aux!= NULL)//em um grafo k-regular todos os vertices possuem grau K
        {
            if(aux->consultarGrauNo() != k)//verifica se o grau do primeiro vertice eh igual aos outros
            {
                return -1;
            }
            else
                proximoNo();
        }
        return k;
    }
    else return -1;
}
bool Grafo::verificarGrafoCompleto() //um grafo completo eh um grafo n-1 regular, onde n = numero de nos
{
    if(verificarKRegular() == (tamanho-1))
        return true;
    else
        return false;
}
int Grafo::ordemGrafo() // retorna a ordem do grafo (numero de nos)
{
    return tamanho;
}
void Grafo::preencherGrafoCompleto()//preenche todas as arestas de maneira a criar o grafo completo
{
    for(int i=1; i<=tamanho; i++)
    {
        for(int j=1; j<=tamanho; j++)
        {
            if(j!=i)
                adicionarAresta(i,j);
        }
    }
}
void Grafo::imprimirGrafo() //imprime os vertices e suas arestas
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
bool Grafo::verificarGrafoConexo()
{
    stack<int> pilha;
    int id=0;
    bool flag = true;
    Bloco* baux;
    bool visitados[tamanho];
    for(int i = 0; i < tamanho; i++)//atribui a todos os indices o estado de nao visitados
        visitados[i] = false;
    inicio();
    while(flag)
    {
        id = (aux->consultarId() - 1);
        if(visitados[id] == false)
        {
            pilha.push(id+1);
            visitados[id] = true;
        }
        baux = aux->consultarAresta();
        if(baux != NULL)
        {
            while(baux!= NULL && visitados[(baux->consultarId()-1)] == true)
            {

                baux = baux->consultarProx();

            }
            if(baux == NULL)
            {
                pilha.pop();
                if(pilha.empty())
                    flag = false;
                else
                    procurarIdNo(pilha.top());
            }
            else
                procurarIdNo(baux->consultarId());
        }
        else
        {
            pilha.pop();
            if(pilha.empty())
                flag = false;
            else
                procurarIdNo(pilha.top());
        }
    }

    for(int i =0; i<tamanho; i++)
    {
        if(visitados[i]==false)
            return false;
    }
    return true;
}
bool Grafo::verificarGrafoBipartido() //problemas
{
    stack<int> pilha;
    int id = 0;
    bool flag = true;
    Bloco* baux;
    bool grupo[tamanho];
    for(int i = 0; i < tamanho; i++)//atribui a todos os indices o estado de nao visitados
        grupo[i] = 0;
    inicio();
    while(flag)
    {
        id = (aux->consultarId() - 1);
        if(grupo[id] == 0)
        {
            if(id == 0)
                grupo[id]=1;
            else
                grupo[id] = (-1)*grupo[(pilha.top()-1)];
            pilha.push(id+1);
        }
        else if(grupo[id] != (-1)*grupo[(pilha.top()-1)])
            return false;
        baux = aux->consultarAresta();
        if(baux != NULL)
        {
            while(baux!= NULL && grupo[(baux->consultarId()-1)] != 0)
            {

                baux = baux->consultarProx();

            }
            if(baux == NULL)
            {
                pilha.pop();
                if(pilha.empty())
                    flag = true;
                else
                    procurarIdNo(pilha.top());
            }
            else
                procurarIdNo(baux->consultarId());
        }
        else
        {
            pilha.pop();
            if(pilha.empty())
                flag = true;
            else
                procurarIdNo(pilha.top());
        }
    }
}

Grafo::~Grafo()//destrutor
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
        delete p;
        p = t;

    }
    cout << "Grafo apagado!";
}

