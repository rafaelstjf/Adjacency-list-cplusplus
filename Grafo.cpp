#include "iostream"
#include "Grafo.h"
#include <ctime>
#include <stack>
using namespace std;

Grafo::Grafo(bool tipo)//construtor
{
    prim = NULL;
    aux = NULL;
    ultimo = NULL;
    orientada = tipo;
    tamanho = 0;
}
//navegacao
void Grafo::inicio()
{
    aux = prim;
}
void Grafo::proximoNo()//avanca o ponteiro aux ate o ultimo no
{
    if(aux != NULL)
    {
        aux = aux->getProxNo();
    }
}
bool Grafo::grafoVazio()//verifica se a lista vazia
{
    if(prim == NULL)
        return true;
    else return false;
}
bool Grafo::existeIdNo(int id)//verifica se o no de id desejado existe
{

    if(!grafoVazio())
    {
        if(id>=prim->getId() && id <=ultimo->getId() )
            return true;
        else
            return false;
    }
    else return false;

}
void Grafo::procurarIdNo(int id)//procurar o no com o id desejado ateh o ultimo no, caso nao encontrado exibe mensagem de no inexistente
{

    if(!grafoVazio())
    {
        inicio();
        while(aux->getId() != id)
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
void Grafo::inserirNo(int val) //insere um novo No ordenado no fim da lista
{
    if(prim == NULL)
    {
        No* c = new No();
        c->setIdNo(val);
        c->setProx(prim);
        prim = c;
        ultimo = c;
        tamanho++;
    }
    else
    {
        inicio();
        while(aux->getProxNo() != NULL && aux->getId() <= val)
        {
            proximoNo();
        }
        if(aux->getId() <= val)
        {
            No* c = new No();
            c->setIdNo(val);
            c->setProx(NULL);
            aux->setProx(c);
            ultimo = c;
        }
        else
        {
            No* c = new No();
            c->setIdNo(val);
            c->setProx(aux);
        }
        tamanho++;
    }
}
void Grafo::adicionarArco(int ini, int fim)
{
    procurarIdNo(ini);
    ListaAdjacencia* l = aux->getArestas();
    if(l!= NULL)
    {
        if(!l->existeIdAresta(fim))
        {
            aux->getArestas()->inserir(fim);
            aux->setGrauNo(aux->getGrauNo() + 1);
        }
        else
        {
            if(orientada)
                cout << "Arco (" << ini <<", " << fim<<") ja existente!" << endl;
        }
    }
    else
    {
        l = new ListaAdjacencia();
        l->inserir(fim);
        aux->setArestas(l);
        aux->setGrauNo(aux->getGrauNo() + 1);
    }
}

void Grafo::adicionarAresta(int ini, int fim)//adiciona aresta/vertice de acordo com o tipo de grafo
{
    if(existeIdNo(ini) && existeIdNo(fim))
    {
        if(orientada)
            adicionarArco(ini, fim);
        else//nao implementado ainda
        {
            adicionarArco(ini,fim);
            adicionarArco(fim, ini);

        }
    }

}
int Grafo::grauNo(int id)
{
    if(existeIdNo(id))//verifica se existe o no de ID desejado
    {
        procurarIdNo(id);
        return aux->getGrauNo();
    }
    else//caso nao encontre o no, retorna o grau como -1
    {
        return -1;
    }

}
void Grafo::preencherGrafoCompleto()
{
    clock_t begin = clock();

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
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << elapsed_secs << " s para gerar o grafo completo" <<endl;
}
int Grafo::grauGrafo()//calcula o grau do grafo; Grau do grafo = grau do maior no
{
    int grauGrafo = -1;
    for(int i = 1; i<=tamanho; i++)
    {
        if(grauGrafo <=grauNo(i))
        {
            grauGrafo  = grauNo(i);
        }
    }
    return grauGrafo;
}
void Grafo::imprimirGrafo() //imprime a lista
{
    inicio();
    ListaAdjacencia* lbaux;
    while(aux != NULL)
    {
        cout << "Vertice ID: " << aux->getId();
        lbaux = aux->getArestas();
        if(lbaux!= NULL)
            lbaux->imprimir();
        cout << endl;
        proximoNo();
    }
}
bool Grafo::verificarAdjacencia(int id1, int id2)//verifica se existe uma aresta ligando os dois Nos desejados
{
    if(existeIdNo(id1) && existeIdNo(id2))
    {
        procurarIdNo(id1);
        if(aux->getArestas() != NULL)
        {
            ListaAdjacencia* l;
            l = aux->getArestas();
            l->inicio();
            while(l->getAux() != NULL && id2 != l->getAux()->getId())//verifica se esta no ultimo bloco e se tem aresta repetida
            {
                l->proximaAresta();
            }
            if(l->getAux()!= NULL && id2 == l->getAux()->getId())//verifica se o while foi parado por ter aresta repetida
                return true;
        }
        else
            return false;
    }
    else
        return false;
}
void Grafo::listarAdjacentesNo(int id) //imprime os adjacentes do No de Id desejado
{
    if(existeIdNo(id))
    {
        procurarIdNo(id);
        cout << "No ID: " << aux->getId() << " e seus adjacentes." << endl;
        cout << aux->getId();
        if(aux->getArestas() != NULL)
            aux->getArestas()->imprimir();
    }
    else
        cout << "O no de ID: " << id << " nao foi encontrado!" << endl;
}
int Grafo::ordemGrafo() // retorna a ordem do grafo (numero de nos)
{
    return tamanho;
}
int Grafo::verificarKRegular()
{
    if(!grafoVazio())
    {
        inicio();
        int k = aux->getGrauNo();
        while(aux!= NULL)//em um grafo k-regular todos os vertices possuem grau K
        {
            if(aux->getGrauNo() != k)//verifica se o grau do primeiro vertice eh igual aos outros
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
bool Grafo::verificarGrafoConexo()
{
    stack<int> pilha;
    int id=0;
    ListaAdjacencia* l;
    bool flag = true;
    bool visitados[tamanho];
    for(int i = 0; i < tamanho; i++)//atribui a todos os indices o estado de nao visitados
        visitados[i] = false;
    inicio();
    while(flag)
    {
        id = (aux->getId() - 1);
        if(visitados[id] == false)
        {
            pilha.push(id+1);
            visitados[id] = true;
        }
        l = aux->getArestas();
        l->inicio();
        if(l != NULL)
        {
            while(l->getAux() != NULL && visitados[(l->getAux()->getId()-1)] == true)
            {

                l->proximaAresta();
            }
            if(l->getAux() == NULL)
            {
                pilha.pop();
                if(pilha.empty())
                    flag = false;
                else
                    procurarIdNo(pilha.top());
            }
            else
                procurarIdNo(l->getAux()->getId());
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
Grafo::~Grafo()//destrutor
{
    No* p = prim;
    while(p != NULL)
    {
        No *t = p->getProxNo();
        delete p->getArestas();
        delete p;
        p = t;

    }
    cout << "Grafo apagado!";
}
