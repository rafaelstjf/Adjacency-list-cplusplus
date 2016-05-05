#include "Grafo.h"

using namespace std;
Grafo::Grafo(bool tipo)//construtor
{
    prim = NULL;
    aux = NULL;
    ultimo = NULL;
    orientada = tipo;
    ordem = 0;
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
                break;
            }
        }
    }
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
        ordem++;
    }
    else
    {
        inicio();
        while(aux->getProxNo() != NULL && aux->getId() <= val)
        {
            proximoNo();
        }
        if(aux->getId() < val)
        {
            No* c = new No();
            c->setIdNo(val);
            c->setProx(NULL);
            c->setAntNo(aux);
            aux->setProx(c);
            ultimo = c;
        }
        else if(aux->getId() == val)
            cout << "No ja existente!" << endl;
        else
        {
            No* c = new No();
            c->setIdNo(val);
            c->setAntNo(aux->getAntNo());
            aux->setAntNo(c);
            c->setProx(aux);
        }
        ordem++;
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
    for(int i=0; i<ordem; i++)
    {
        for(int j=0; j<ordem; j++)
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
    for(int i = 1; i<=ordem; i++)
    {
        if(grauGrafo <=grauNo(i))
        {
            grauGrafo  = grauNo(i);
        }
    }
    return grauGrafo;
}
string Grafo::exibirGrafo() //exibe a lista
{
    stringstream stream;
    inicio();
    ListaAdjacencia* lbaux;
    stream << "\n";
    while(aux != NULL)
    {
        stream << "Vertice ID: " << aux->getId();

        if(aux->getArestas()!= NULL){
            lbaux = aux->getArestas();
        lbaux->inicio();
        while(lbaux->getAux()!= NULL)
        {
            stream << "-> " << lbaux->getAux()->getId() << " ";
            lbaux->proximaAresta();
        }
        }
        stream << "\n";
        proximoNo();
    }
    return stream.str();
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
string Grafo::listarAdjacentesNo(int id) //imprime os adjacentes do No de Id desejado
{
    stringstream stream;
    stream << "\n";
    ListaAdjacencia* lbaux;
    if(existeIdNo(id))
    {
        procurarIdNo(id);
        stream << "No ID: " << aux->getId() << " e seus adjacentes.\n";
        stream << aux->getId();
        lbaux = aux->getArestas();
        if(lbaux!= NULL)
            lbaux->inicio();
        while(lbaux->getAux()!= NULL)
        {
            stream << "->" << lbaux->getAux()->getId() << " ";
            lbaux->proximaAresta();
        }
    }
    else
        stream << "O no de ID: " << id << " nao foi encontrado!\n";
    return stream.str();
}
int Grafo::ordemGrafo() // retorna a ordem do grafo (numero de nos)
{
    return ordem;
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
    if(verificarKRegular() == (ordem-1))
        return true;
    else
        return false;
}
bool Grafo::verificarGrafoConexo()
{
    ListaAdjacencia* l;
    inicio();
    bool visitados[ordem];
    for(int i =0; i<ordem; i++)
        visitados[i] = false;
    stack<int> pilha;
    int numVis = 1;
    int ant = 0;
    visitados[aux->getId()] = true;
    pilha.push(aux->getId());
    while(!pilha.empty())
    {
        procurarIdNo(pilha.top());
        ant = aux->getId();
        pilha.pop();
        l = aux->getArestas();
        if(l!=NULL)
        {
            l->inicio();
            while(l->getAux()!= NULL)
            {
                if(!visitados[l->getAux()->getId()] && l->getAux()->getId() != ant)
                {
                    visitados[l->getAux()->getId()] = true;
                    numVis++;
                    pilha.push(l->getAux()->getId());
                }
                l->proximaAresta();
            }
        }
    }
    if(numVis == ordem)
        return true;
    else
        return false;
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
        No* n = aux;
        if(aux == prim && aux !=ultimo)
        {
            prim = aux->getProxNo();
            prim->setAntNo(NULL);

        }
        else if(aux == ultimo && aux!=prim)
        {
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

            aux = n->getAntNo();
            aux->setProx(n->getProxNo());
            No* aux2 = n->getProxNo();
            aux2->setAntNo(aux);
        }
        delete n;
    }
}
bool Grafo::verificarGrafoBipartido()
{
    No* temporario = NULL;
    int vertice[ordem];//cria um vetor com os grupos
    for(int i =0; i<ordem; i++)
        vertice[i] = -1;
    inicio();
    while(aux!=NULL)
    {
        temporario = aux;
        if(vertice[aux->getId()]== -1)
        {
            //chama o bipartidoaux para cada no do grafo
            if(bipartidoAux(temporario, vertice, 0)== 0) return false;//se o bipartidoaux retornar grupo repetido entao nao eh bipartido
            aux = temporario;
        }
        proximoNo();
    }
    return true;
}
bool Grafo::bipartidoAux(No* n, int vertice[], int c)
{
    vertice[n->getId()] = 1-c;
    ListaAdjacencia* l = aux->getArestas();
    if(l!=NULL)
    {
        l->inicio();
        while(l->getAux()!= NULL)
        {
            if(vertice[l->getAux()->getId()] == -1)
            {
                procurarIdNo(l->getAux()->getId());
                if(bipartidoAux(aux, vertice,1-c ) == false) return false;
            }
            else if(vertice[l->getAux()->getId()] == 1-c) return false;
            l->proximaAresta();

        }
        return true;
    }
    return false;

}
Grafo* Grafo::grafoComplementar()
{
    Grafo* g = new Grafo(orientada);
    for(int  i = 0; i<ordem; i++)
        g->inserirNo(i);
    ListaAdjacencia* lista = NULL;
    inicio();
    while(aux!= NULL)
    {
        lista = aux->getArestas();
        if(lista != NULL)
            for(int i = 1; i<=ordem; i++)
                if(!lista->existeIdAresta(i))
                    g->adicionarAresta(aux->getId(), i);
        proximoNo();
    }
    return g;
}

Grafo* Grafo::grafoInduzido(int tam, int vet[])
{
    ListaAdjacencia* l;
    Grafo* g = new Grafo(orientada);
    bool del[ordem];//vetor com a ordem do grafo
    for(int i = 0; i< ordem; i++)
        del[i] = true;
    for(int i = 0; i<tam; i++)
        del[vet[i]] = false;
    inicio();
    for(int i = 0; i<ordem; i++)
    {
        if(del[i] == false)
            g->inserirNo(i);
    }
    inicio();
    for(int i = 0; i<ordem; i++)
    {
        if(del[i] == false)
        {
            procurarIdNo(i);
            l = aux->getArestas();
            if(l!= NULL)
            {
                while(l->getAux()!= NULL)
                {
                    g->adicionarAresta(i, l->getAux()->getId());
                    l->proximaAresta();
                }
            }
        }
    }
    return g;
}


bool Grafo::verificarNoArticulacao(int idBusca)
{

}
bool Grafo::verificarArestaPonte(int ini, int fim) {}
Grafo::~Grafo()//destrutor
{
    No* p = prim;
    while(p != NULL)
    {
        No *t = p->getProxNo();
        if(p->getArestas()!= NULL)
            delete p->getArestas();
        delete p;
        p = t;

    }
    cout << "Grafo apagado!" << endl;;
}
