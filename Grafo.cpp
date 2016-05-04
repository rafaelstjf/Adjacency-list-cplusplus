#include "iostream"
#include "Grafo.h"
#include "ListaAdjacencia.h"
#include <stack>
using namespace std;
Grafo::Grafo(int tam, bool tipo)//construtor
{
    prim = NULL;
    aux = NULL;
    ultimo = NULL;
    orientada = tipo;
    tamanho = 0;
    for(int  i = 0; i<tam; i++)
        inserirNo(i+1);
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
void Grafo::limpaVisitados()
{
    inicio();
    while(aux!= NULL)
    {
        aux->setVisitado(false);
        proximoNo();
    }
}
//manipulacao
void Grafo::inserirNo(int val) //insere um novo No ordenado no fim da lista
{
    if(prim == NULL)
    {
        No* c = new No();
        c->setIdNo(val);
        c->setProx(prim);
        c->setArestas(NULL);
        c->setAntNo(NULL);
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
            c->setAntNo(aux);
            aux->setProx(c);
            ultimo = c;
        }
        else
        {
            No* c = new No();
            c->setIdNo(val);
            c->setAntNo(aux->getAntNo());
            aux->setAntNo(c);
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

void Grafo::adicionarAresta(int ini, int fim)//adiciona aresta/arco de acordo com o tipo de grafo
{
    if(existeIdNo(ini) && existeIdNo(fim) && ini!=fim)
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
void Grafo::exibirGrafo() //exibe a lista
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
    limpaVisitados();
    inicio();
    while(aux!= NULL)
    {
        if(aux->getVisitado() == false)
            verificarGrafoConexoAux(aux);
        proximoNo();
    }
    inicio();
    while(aux!=NULL)
    {
        if(aux->getVisitado()==true)
            proximoNo();
        else
        {
            return false;
            break;

        }
    }
    return true;
}
void Grafo::verificarGrafoConexoAux(No* v)
{
    ListaAdjacencia* l = NULL;
    v->setVisitado(true);
    if(v->getArestas()!=NULL)
    {
        l = v->getArestas();
        while(l->getAux() != NULL)
        {
            procurarIdNo(l->getAux()->getId());
            if(aux->getVisitado() == false)
                verificarGrafoConexoAux( aux);
            l->proximaAresta();
        }
    }
}
void Grafo::removerNo(int id)
{
    ListaAdjacencia* l = NULL;
    if(existeIdNo(id))
    {
        inicio();
        while(aux!= NULL)
        {
            l = aux->getArestas();
            if(l != NULL)
            {
                l->removerAresta(id);
            }

            proximoNo();
        }
        procurarIdNo(id);
        No* n;
        if(aux == prim && aux !=ultimo)
        {
            prim = aux->getProxNo();
            prim->setAntNo(NULL);

        }
        else if(aux == ultimo && aux!=prim)
        {
            n = aux;
            aux = n->getAntNo();
            aux->setProx(NULL);
            ultimo = aux;

        }
        else if(aux == prim && aux == ultimo)
        {
            prim = NULL;
            ultimo = NULL;
        }
        else
        {
            n = aux;
            aux = n->getAntNo();
            aux->setProx(n->getProxNo());
        }
        delete n;
    }
}
bool Grafo::verificarGrafoBipartido()
{
    No* temporario = NULL;
    int vertice[tamanho];//cria um vetor com os grupos
    for(int i =0; i<tamanho; i++)
        vertice[i] = -1;
    inicio();
    while(aux!=NULL)
    {
        temporario = aux;
        if(vertice[aux->getId()-1]== -1)
        {//chama o bipartidoaux para cada no do grafo
            if(bipartidoAux(temporario, vertice, 0)== 0) return false;//se o bipartidoaux retornar grupo repetido entao nao eh bipartido
            aux = temporario;
        }
        proximoNo();
    }
    return true;
}
bool Grafo::bipartidoAux(No* n, int vertice[], int c)
{
    vertice[n->getId()-1] = 1-c;
    ListaAdjacencia* l = aux->getArestas();
    if(l!=NULL)
    {
        l->inicio();
        while(l->getAux()!= NULL)
        {
            if(vertice[l->getAux()->getId()-1] == -1)
            {
                procurarIdNo(l->getAux()->getId());
                if(bipartidoAux(aux, vertice,1-c ) == false) return false;
            }
            else if(vertice[l->getAux()->getId()-1] == 1-c) return false;
                        l->proximaAresta();

        }
        return true;
    }
    return false;

}
Grafo* Grafo::grafoComplementar()
{
    Grafo* g = new Grafo(tamanho, orientada);
    ListaAdjacencia* lista = NULL;
    inicio();
    while(aux!= NULL)
    {
        lista = aux->getArestas();
        if(lista != NULL)
            for(int i = 1; i<=tamanho; i++)
                if(!lista->existeIdAresta(i))
                    g->adicionarAresta(aux->getId(), i);
        proximoNo();
    }
    return g;
}

Grafo* Grafo::grafoInduzido(int tam, int vet[])
{
    Grafo* g;
    stack<int> pilha;
    ListaAdjacencia* l;
    while(!pilha.empty())
        pilha.pop();
    inicio();
    if(tam>0)//verifica se o tamanho do vetor eh positivo e diferente de zero
    {
        g = new Grafo(tamanho, orientada);
        while(aux!= NULL)//cria uma pilha de exclusao
        {
            for(int i = 0; i<tam; i++)
            {
                if(aux->getId() != vet[i])
                {
                    if(pilha.empty() || pilha.top() != aux->getId())
                        pilha.push(aux->getId());
                }
                else if(!pilha.empty() && pilha.top() == aux->getId())
                {
                    pilha.pop();
                    i = tam-1;
                }
                else
                    i = tam-1;
            }
            proximoNo();
        }
        while(!pilha.empty())
        {
            g->removerNo(pilha.top());
            pilha.pop();
        }
        for(int i = 0; i < tam; i++)
        {
            if(existeIdNo(vet[i]))
            {
                procurarIdNo(vet[i]);
                l = aux->getArestas();
                if(l!= NULL)
                {
                    l->inicio();
                    while(l->getAux() != NULL)
                    {
                        int fim = l->getAux()->getId();
                        g->adicionarAresta(vet[i],fim);
                        l->proximaAresta();
                    }
                }
            }
        }
    }
    else
        g = new Grafo(0, orientada);
    return g;
}
bool Grafo::verificarNoArticulacao(int idBusca)
{


}
void verificarNoArticulacaoAux(No* v)
{

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
