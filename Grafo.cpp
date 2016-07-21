#include "Grafo.h"
using namespace std;

/*
======================= Grafo(bool tipo) =======================
	Construtor do grafo
	Parametros:
	bool tipo -> Booleano para definir se o grafo é orientado ou nao.
*/
Grafo::Grafo(bool tipo)
{
    prim = NULL;
    aux = NULL;
    ultimo = NULL;
    orientada = tipo;
    ordem = 0;
}
/*
======================= inicio() =======================
	metodo para colocar o no aux apontando para a primeiro no
	Parametros:
	-nenhum-
*/
void Grafo::inicio()//coloca aux apontando para a primeiro no
{
    aux = prim;
}
/*
======================= inicio() =======================
	metodo para colocar o no aux apontando para o no seguinte
	Parametros:
	-nenhum-
*/
void Grafo::proximoNo()//avanca o ponteiro aux ate o ultimo no
{
    if(aux != NULL)
        aux = aux->getProxNo();
}
/*
======================= grafoVazio() =======================
	funcao booleana para verificar se o grafo esta vazio
	Parametros:
	-nenhum-
*/
bool Grafo::grafoVazio()
{
    if(prim == NULL)
        return true;
    else return false;
}
/*
======================= existeIdNo(int id) =======================
	funcao booleana para verificar se existe determinado no
	Parametros:
	int id-> Inteiro contendo o id do no desejado
*/
bool Grafo::existeIdNo(int id)
{

    if(!grafoVazio())
    {
        inicio();
        while(aux!=NULL)
        {
            if(aux->getId() == id)
                return true;
            proximoNo();
        }
        return false;
    }
    else return false;

}
/*
======================= procurarIdNo(int id) =======================
	metodo para colocar o no aux apontando para o no de id desejado
	Parametros:
	int id-> Inteiro contendo o id do no
*/
void Grafo::procurarIdNo(int id)
{
    if(!grafoVazio())
    {
        inicio();
        while(aux->getId() != id)
        {
            proximoNo();
            if(aux==NULL)
                break;
        }
    }
}
/*
======================= limpaVisitados() =======================
	metodo para colocar o valor da variavel visitado como false
	Parametros:
	-nenhum-
*/
void Grafo::limpaVisitados()
{
    inicio();
    while(aux!= NULL)
    {
        aux->setVisitado(false);
        proximoNo();
    }
}
/*
======================= inserirNo(int val) =======================
	metodo para inserir um novo no ordenado na lista de
	adjacencia
	Parametros:
	val-> Inteiro contendo o id do no
*/
void Grafo::inserirNo(int val)
{
    No* c = new No();
    c->setIdNo(val);
    c->setArestas(NULL);
    if(prim == NULL)
    {
        c->setProx(prim);
        c->setAntNo(NULL);
        prim = c;
        ultimo = c;
        ordem++;
    }
    else
    {
        if(val < ultimo->getId())
        {
            inicio();
            while(aux->getProxNo() != NULL && aux->getId() < val)
                proximoNo();
            if(aux == prim)
            {
                c->setAntNo(NULL);
                c->setProx(aux);
                prim = c;
            }
            else
            {
                c->setAntNo(aux->getAntNo());
                c->setProx(aux);
                No* aux2 = aux->getAntNo();
                aux2->setProx(c);
                aux->setAntNo(c);
            }
        }
        else if(aux!= NULL && aux->getId() == val)
            cout << "No ja existente!" << endl;
        else
        {
            c->setProx(NULL);
            c->setAntNo(ultimo);
            ultimo->setProx(c);
            ultimo = c;
        }
        ordem++;
    }
}
/*
======================= adicionar(int ini, int fim, int peso) =======================
	metodo para adicionar uma ligacao do no de id ini
	para o de id fim com o peso desejado
	Parametros:
	ini-> Inteiro cotendo o id do no inicial
	fim-> Inteiro contendo o id do no final
	peso-> Inteiro contendo o peso da ligacao
*/
void Grafo::adicionar(int ini, int fim, int peso)
{
    procurarIdNo(ini);
    ListaAdjacencia* l = aux->getArestas();
    if(l!= NULL)
    {
        if(!l->existeIdAresta(fim))
        {
            aux->getArestas()->inserir(fim,peso);
            aux->setGrauNo(aux->getGrauNo() + 1);
        }
    }
    else
    {
        l = new ListaAdjacencia();
        l->inserir(fim, peso);
        aux->setArestas(l);
        aux->setGrauNo(aux->getGrauNo() + 1);
    }
}
/*
======================= adicionarAresta(int ini, int fim, int peso) =======================
	metodo para adicionar uma aresta ou arco do no de id ini
	para o de id fim com o peso desejado
	Parametros:
	ini-> Inteiro cotendo o id do no inicial
	fim-> Inteiro contendo o id do no final
	peso-> Inteiro contendo o peso da ligacao
*/
void Grafo::adicionarAresta(int ini, int fim, int peso)
{
    if(existeIdNo(ini) && existeIdNo(fim) && ini!=fim)
    {
        if(orientada)
            adicionar(ini, fim, peso);
        else
        {
            adicionar(ini,fim, peso);
            adicionar(fim, ini, peso);
        }
    }
}
/*
======================= grauNo(int id) =======================
	funcao inteira para verificar e retornar o grau do No
	desejado
	Parametros:
	id-> Inteiro contendo o id do no desejado
*/
int Grafo::grauNo(int id)
{
    if(existeIdNo(id))
    {
        procurarIdNo(id);
        return aux->getGrauNo();
    }
    else//caso nao encontre o no, retorna o grau como -1
        return -1;
}
/*
======================= grauGrafo() =======================
	funcao inteira para verificar e retornar o grau do grafo
	desejado
	Parametros:
	-nenhum-
*/
int Grafo::grauGrafo()
{
    int grauGrafo = -1;
    for(int i = 1; i<=ordem; i++)
    {
        if(grauGrafo <=grauNo(i))
            grauGrafo  = grauNo(i);
    }
    return grauGrafo;
}
/*
======================= exibirGrafo() =======================
	funcao do tipo String para armazenar o grafo no formato
	V1 V2 P, onde o par (V1,V2) corresponde a uma ligacao de
	peso P
	Parametros:
	-nenhum-
*/
string Grafo::exibirGrafo()
{
    stringstream stream;
    inicio();
    ListaAdjacencia* lbaux;
    stream << "\n";
    while(aux != NULL)
    {

        if(aux->getArestas()!= NULL)
        {
            lbaux = aux->getArestas();
            lbaux->inicio();
            while(lbaux->getAux()!= NULL)
            {
                stream << aux->getId() << " " << lbaux->getAux()->getId() << " " << lbaux->getAux()->getPeso()<< "\n";
                lbaux->proximaAresta();
            }
        }
        proximoNo();
    }
    return stream.str();
}
/*
======================= verificarAdjacencia(int id1, int id2) =======================
	funcao Booleana para verificar se dois nos sao adjacentes
	Parametros:
	id1-> Inteiro contendo o valor do no inicial
	id2-> Inteiro contendo o valor do no final
*/
bool Grafo::verificarAdjacencia(int id1, int id2)
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
/*
======================= listarAdjacentesNo(int id) =======================
	funcao do tipo String para armazenar e retornar todos os
	adjacentes de um no de id desejado
	Parametros:
	id-> Inteiro contendo o id do no desejado
*/
string Grafo::listarAdjacentesNo(int id)
{
    stringstream stream;
    stream << "\n";
    ListaAdjacencia* lbaux;
    if(existeIdNo(id))
    {
        procurarIdNo(id);
        stream << "No ID: " << aux->getId() << " e seus adjacentes.\n";
        lbaux = aux->getArestas();
        if(lbaux!= NULL)
        {
            lbaux->inicio();
            while(lbaux->getAux()!= NULL)
            {
                stream << aux->getId() << " " << lbaux->getAux()->getId() << " " <<lbaux->getAux()->getPeso()<< "\n";
                lbaux->proximaAresta();
            }
        }
    }
    else
        stream << "O no de ID: " << id << " nao foi encontrado!\n";
    return stream.str();
}
/*
======================= ordemGrafo() =======================
	funcao do tipo Inteiro para retornar a ordem do grafo
	Parametros:
	-nenhum-
*/
int Grafo::ordemGrafo()
{
    return ordem;
}
/*
======================= verificarKRegular() =======================
	funcao do tipo Inteiro para verificar se o grafo eh
	K-regular
	Parametros:
	-nenhum-
*/
int Grafo::verificarKRegular()
{
    if(!grafoVazio())
    {
        inicio();
        int k = aux->getGrauNo();
        while(aux!= NULL)//em um grafo k-regular todos os vertices possuem grau K
        {
            if(aux->getGrauNo() != k)//verifica se o grau do primeiro vertice é igual aos outros
            {
                return -1;//retorna -1 ou seja, o grafo nao é k-regular
            }
            else
                proximoNo();
        }
        return k;
    }
    else return -1;
}
/*
======================= verificarGrafoCompleto() =======================
	funcao do tipo Booleana para verificar se o grafo eh completo
	Parametros:
	-nenhum-
*/
bool Grafo::verificarGrafoCompleto()
{
    if(verificarKRegular() == (ordem-1))//um grafo completo é um grafo n-1 regular, onde n = numero de nos
        return true;
    else
        return false;
}
/*
======================= verificarGrafoConexo() =======================
	funcao do tipo Inteiro para verificar se o grafo eh conexo
	Parametros:
	-nenhum-
*/
bool Grafo::verificarGrafoConexo()
{
    ListaAdjacencia* l;
    inicio();
    bool visitados[(ultimo->getId()+1)];
    for(int i =0; i<(ultimo->getId()+1); i++)
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
/*
======================= removerNo(int id) =======================
	metodo para remover um no de id desejado
	Parametros:
	id-> Inteiro contendo o id do no desejado
*/
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
/*
======================= verificarGrafoBipartido() =======================
	funcao do tipo Inteiro para verificar se o grafo eh bipartido
	Parametros:
	-nenhum-
*/
bool Grafo::verificarGrafoBipartido()
{
    No* temporario = NULL;
    int vertice[(ultimo->getId()+1)];//cria um vetor com os grupos
    for(int i =0; i<(ultimo->getId()+1); i++)
        vertice[i] = -1;
    inicio();
    while(aux!=NULL)
    {
        temporario = aux;
        if(vertice[aux->getId()]== -1)
        {
            //chama o bipartidoaux para cada no do grafo
            if(bipartidoAux(temporario, vertice, 0)== 0) return false;//se o bipartidoaux retornar grupo repetido entao nao é bipartido
            aux = temporario;
        }
        proximoNo();
    }
    return true;
}
/*
======================= bipartidoAux(No* n, int vertice[], int c) =======================
	funcao do tipo Booleana para auxiliar a funcao verificarGrafoBipartido()
	Parametros:
	n-> No* no temporario
	vertice-> Inteiro[] vetor com os grupos
	c-> Inteiro contendo iteracao
*/
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
/*
======================= grafoComplementar() =======================
	funcao do tipo Grafo* para gerar e retornar o grafo complementar
	Parametros:
	-nenhum-
*/
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
                    g->adicionarAresta(aux->getId(), i, 0);
        proximoNo();
    }
    return g;
}
/*
======================= grafoInduzido() =======================
	funcao do tipo Grafo* para gerar e retornar o grafo induzido
	Parametros:
	-nenhum-
*/
Grafo* Grafo::grafoInduzido(int tam, int vet[])
{
    ListaAdjacencia* l;
    Grafo* g = new Grafo(orientada);
    bool del[(ultimo->getId()+1)];//vetor com a ordem do grafo
    for(int i = 0; i< (ultimo->getId()+1); i++)
        del[i] = true;
    for(int i = 0; i<tam; i++)
    {
        if(existeIdNo(vet[i]))
        {
            del[vet[i]] = false;
        }
    }
    inicio();
    for(int i = 0; i<(ultimo->getId()+1); i++)
    {
        if(del[i] == false)
            g->inserirNo(i);
    }
    inicio();
    for(int i = 0; i<(ultimo->getId()+1); i++)
    {
        if(del[i] == false)
        {
            procurarIdNo(i);
            l = aux->getArestas();

            if(l!= NULL)
            {
                l->inicio();
                while(l->getAux()!= NULL)
                {
                    g->adicionarAresta(i, l->getAux()->getId(),l->getAux()->getPeso());
                    l->proximaAresta();
                }
            }
        }
    }
    return g;
}
/*
======================= contarComponentesConexas() =======================
	funcao do tipo Inteiro para retornar o numero de componentes conexas
	do grafo
	Parametros:
	-nenhum-
*/
int Grafo::contarComponentesConexas()
{
    if(ultimo!=NULL)
    {
        int* componentes = new int[(ultimo->getId()+1)];
        int cc = 0;
        for(int i = 0; i<(ultimo->getId()+1); i++)
            componentes[i] = 0;
        inicio();
        while(aux!=NULL)
        {
            if(componentes[aux->getId()] == 0)
            {
                cc++;
                componentesConexasAux(aux, cc, componentes);
            }
            proximoNo();
        }
        return cc;
    }
    else return 0;
}
/*
======================= componentesConexasAux(No* temp, int cc, int* componentes) =======================
	metodo auxiliar da funcao contarComponentesConexas()
	Parametros:
	temp-> No* no temporario
	cc-> Inteiro contendo o numero de componentes conexas atuais
	Componentes-> Inteiro* vetor contendo as componentes autais de cada no
*/
void Grafo::componentesConexasAux(No* temp, int cc, int* componentes)
{
    int exTop = 0, nTop = 0;
    ListaAdjacencia* l;
    stack<int> pilha;
    componentes[temp->getId()] = cc;
    pilha.push(temp->getId());
    while(!pilha.empty())
    {
        procurarIdNo(pilha.top());
        temp = aux;
        exTop = pilha.top();
        pilha.pop();
        if(temp->getArestas()!=NULL)
        {

            l= temp->getArestas();
            l->inicio();
            while(l->getAux()!=NULL)
            {
                nTop = l->getAux()->getId();
                if(componentes[nTop] == 0 && nTop != exTop)
                {
                    componentes[nTop] = cc;
                    pilha.push(nTop);
                }
                l->proximaAresta();
            }

        }
    }
}
/*
======================= verificarArestaPonte(int ini, int fim) =======================
	funcao do tipo Booleana para verificar se a aresta desejada eh ponte
	Parametros:
	ini-> Inteiro contendo o no inicial
	fim-> Inteiro contendo o no final

*/
bool Grafo::verificarArestaPonte(int ini, int fim)
{
    int pesoFim = 0;
    ListaAdjacencia* l ;
    if(existeIdNo(ini) && existeIdNo(fim))
    {

        if(orientada)
        {
            procurarIdNo(ini);
            int ccAntes = contarComponentesConexas();
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->procurarIdAresta(fim);
                pesoFim = l->getAux()->getPeso();
                l->removerAresta(fim);
            }
            int ccDepois = contarComponentesConexas();
            procurarIdNo(ini);
            adicionarAresta(ini, fim, pesoFim);
            if(ccAntes<ccDepois)
                return true;
            else
                return false;
        }
        else
        {
            int ccAntes = contarComponentesConexas();
            procurarIdNo(ini);
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->procurarIdAresta(fim);
                pesoFim = l->getAux()->getPeso();
                l->removerAresta(fim);
            }
            procurarIdNo(fim);
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->removerAresta(ini);
            }
            int ccDepois = contarComponentesConexas();
            procurarIdNo(ini);
            adicionarAresta(ini, fim, pesoFim);
            if(ccAntes<ccDepois)
                return true;
            else
                return false;
        }
    }
    else return false;
}
/*
======================= verificarNoArticulacao(int idBusca) =======================
	funcao do tipo Booleana para verificar se o no desejado eh de articulacao
	Parametros:
	idBusca-> Inteiro contendo o id do no desejado
*/
bool Grafo::verificarNoArticulacao(int idBusca)
{
    if(existeIdNo(idBusca))
    {
        int ccAntes = contarComponentesConexas();
        int* componentes = new int[(ultimo->getId()+1)];
        int ccDepois = 0;
        for(int i = 0; i<(ultimo->getId()+1); i++)
            componentes[i] = 0;
        componentes[idBusca]  = 1;
        inicio();
        while(aux!=NULL)
        {
            if(componentes[aux->getId()] == 0)
            {
                ccDepois++;
                componentesConexasAux(aux, ccDepois, componentes);
            }
            proximoNo();
        }
        if(ccAntes<ccDepois)
            return true;
        else return false;
    }
    else return false;

}
/*
======================= grafoTransposto() =======================
	funcao do tipo Grafo* retornar o grafo transposto
	Parametros:
	-nenhum-
*/
Grafo* Grafo::grafoTransposto()
{
    Grafo* transp = new Grafo(orientada);
    ListaAdjacencia* l;
    inicio();
    while(aux!= NULL)
    {
        transp->inserirNo(aux->getId());
        proximoNo();
    }
    inicio();
    while(aux!= NULL)
    {
        l = aux->getArestas();
        if(l!= NULL)
        {
            l->inicio();
            while(l->getAux()!= NULL)
            {
                transp->adicionarAresta(l->getAux()->getId(), aux->getId(), l->getAux()->getPeso());//cria uma aresta com sentido contrario
                l->proximaAresta();
            }
        }
        proximoNo();
    }
    return transp;
}

int* Grafo::fechoTransitivoAux(int id)
{
    stack<int> conjunto;
    ListaAdjacencia* l;
    bool visitados[(ultimo->getId()+1)];
    for(int i =0; i<(ultimo->getId()+1); i++)
        visitados[i] = false;
    stack<int> pilha;
    int ant = 0;
    visitados[id] = true;
    procurarIdNo(id);
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
                    pilha.push(l->getAux()->getId());
                }
                l->proximaAresta();
            }
        }
    }
    conjunto.push(id);
    int u =0;
    while(u<(ultimo->getId()+1))
    {
        if(visitados[u] == true && u!= id)
            conjunto.push(u);
        u++;
    }
    int* vetConjunto = new int[conjunto.size()+1];//um indice para guardar o tamanho
    for(int i = 0; i<conjunto.size()+1; i++)
        vetConjunto[i] = 0;
    vetConjunto[0] = conjunto.size()+1;//guardar tamanho no indice 0
    for(int i = 1; i<vetConjunto[0]; i++)
    {
        vetConjunto[i] = conjunto.top();
        conjunto.pop();
    }
    return vetConjunto;
}
string Grafo::fechoTransitivoDireto(int id)
{
    stringstream stream;
    stream << "Vertices alcancados a partir do vertice de ID: " << id<<" (Fecho transitivo direto fechado):\n {";
    int* vet = fechoTransitivoAux(id);
    int tamVet = vet[0];
    for(int i = 1; i<tamVet; i++)
    {
        stream << vet[i];
        if(i < tamVet -1)
            stream << ", ";
    }
    stream << "}";
    return stream.str();
}

string Grafo::fechoTransitivoIndireto(int id)
{
    stringstream stream;
    Grafo* g1 = grafoTransposto();
    stream << "Vertices que alcancam o vertice de ID: " << id<<" (Fecho transitivo indireto fechado):\n {";
    int* vet = g1->fechoTransitivoAux(id);
    int tamVet = vet[0];
    for(int i = 1; i<tamVet; i++)
    {
        stream << vet[i];
        if(i < tamVet -1)
            stream << ", ";
    }
    stream << "}";
    return stream.str();
}
void Grafo::removerAresta(int ini, int fim)//remove uma aresta
{
    if(existeIdNo(ini) && existeIdNo(fim ))
    {
        ListaAdjacencia* l;
        if(orientada)
        {
            procurarIdNo(ini);
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->removerAresta(fim);
                aux->setGrauNo(aux->getGrauNo()-1);
            }
        }
        else
        {
            procurarIdNo(ini);
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->removerAresta(fim);
                aux->setGrauNo(aux->getGrauNo()-1);
            }
            procurarIdNo(fim);
            l = aux->getArestas();
            if(l!=NULL)
            {
                l->removerAresta(ini);
                aux->setGrauNo(aux->getGrauNo()-1);
            }
        }
    }
}
ListaDEncad* Grafo::heuristica()
{
//heuristica apenas ordena
    ListaDEncad* listaIds = new ListaDEncad();
    inicio();
    while(aux!=NULL)
    {
        listaIds->inserirOrdGrau(aux->getId(), aux->getGrauNo());
        proximoNo();
    }
    return listaIds;
}
bool Grafo::verificadorViabilidade(ListaDEncad* conjSolucao)
{
    int ElementosConj[conjSolucao->getTamanho()];
    int i = 0, numCC = 0;
    conjSolucao->inicio();
    while(conjSolucao->getIt()!=NULL)
    {
        ElementosConj[i] = conjSolucao->getIt()->getId();
        i++;
        conjSolucao->proxBloco();
    }
    Grafo* gInd = grafoInduzido(i+1, ElementosConj);
    numCC = gInd->contarComponentesConexas();

    if(numCC==conjSolucao->getTamanho())
    {
        delete gInd;
        return true;
    }
    else
    {
        delete gInd;
        return false;
    }
}
ListaDEncad* Grafo::algoritmoGuloso()
{
    ListaDEncad* candidatos;
    ListaAdjacencia* adjacentes;
    candidatos = heuristica();
    ListaDEncad* conjSolucao = new ListaDEncad();
    int idAtual = 0, adjAtual = 0, grauAtual = 0;
    candidatos->inicio();
    while(candidatos->getIt()!=NULL)
    {
        idAtual = candidatos->getIt()->getId();
        grauAtual = candidatos->getIt()->getGrau();
        procurarIdNo(idAtual);
        adjacentes = aux->getArestas();
        if(adjacentes!=NULL)
        {
            adjacentes->inicio();
            while(adjacentes->getAux()!=NULL)
            {
                adjAtual = adjacentes->getAux()->getId();
                candidatos->removerId(adjAtual);
                adjacentes->proximaAresta();
            }
            conjSolucao->inserirOrdGrau(idAtual, grauAtual);
        }
        candidatos->removerId(idAtual);
        candidatos->inicio();
    }
    if(verificadorViabilidade(conjSolucao))
        return conjSolucao;
    else
        return NULL;

}
ListaDEncad* Grafo::algGulosoAleatoriedadeParam(double alfa)
{
    ListaDEncad* candidatos;
    ListaAdjacencia* adjacentes;
    candidatos = heuristica();
    ListaDEncad* conjSolucao = new ListaDEncad();
    int idAtual = 0, adjAtual = 0, grauAtual = 0, k = 0, tAlfa = 0;
    tAlfa = alfa*candidatos->getTamanho();
    if(tAlfa == 0)
        k = 0;
    else
        k = rand() % tAlfa;
    candidatos->inicio();
    for(int j=1; j<=candidatos->getTamanho(); j++)
    {
        if(j==k)
        {
            idAtual = candidatos->getIt()->getId();
            grauAtual = candidatos->getIt()->getGrau();
            conjSolucao->inserirOrdGrau(idAtual, grauAtual);
            procurarIdNo(idAtual);
            adjacentes = aux->getArestas();
            if(adjacentes!=NULL)
            {
                adjacentes->inicio();
                while(adjacentes->getAux()!=NULL)
                {
                    adjAtual = adjacentes->getAux()->getId();
                    candidatos->removerId(adjAtual);
                    adjacentes->proximaAresta();
                }
            }
            candidatos->removerId(idAtual);
            break;
        }
        candidatos->proxBloco();
    }
    candidatos->inicio();
    while(candidatos->getIt()!=NULL)
    {
        idAtual = candidatos->getIt()->getId();
        grauAtual = candidatos->getIt()->getGrau();
        procurarIdNo(idAtual);
        adjacentes = aux->getArestas();
        if(adjacentes!=NULL)
        {
            adjacentes->inicio();
            while(adjacentes->getAux()!=NULL)
            {
                adjAtual = adjacentes->getAux()->getId();
                candidatos->removerId(adjAtual);
                adjacentes->proximaAresta();
            }
        }
        conjSolucao->inserirOrdGrau(idAtual, grauAtual);
        candidatos->removerId(idAtual);
        candidatos->inicio();
    }
    conjSolucao->setAlfa(alfa);
    conjSolucao->inicio();
    if(verificadorViabilidade(conjSolucao))
        return conjSolucao;
    else return NULL;

}
int Grafo::probRandom(int tam, double prob[])
{
    int soma = 0;
    int nRand = 0;
    for(int i = 0; i<tam; i++)
    {
        soma+=prob[i]*1000;

    }
    nRand = (soma > 0)?rand() % soma:0;
    soma  = 0;
    for(int i = 0; i<tam; i++)
    {
        soma+=prob[i]*1000;
        if(nRand <= soma)
            return i;
    }
}
ListaDEncad* Grafo::algGulosoAleatoriedadeAuto(int tam, double conjAlfa[])
{
    ListaDEncad* melhorSol = new ListaDEncad();
    ListaDEncad* solAtual;
    double prob[tam];
    double media[tam];
    int valoresEncontrados[tam];
    double q[tam];
    int nAlfa[tam];
    int maxIt = 1500, bIteracao = 100, numblocos = 0, itAt = 0, indice = 0,  gama  = 10, emBloco = 1;
    double  alfaAt = 0.0,  somQ = 0.0;
    bool resetar = false;
    for(int i = 0; i < tam; i++)
    {
        valoresEncontrados[i] = 0;
        prob[i] = 1.0/tam;
        media[i] = 0.0;
        nAlfa[i] = 0;
        q[i] = 0.0;
    }
    for(itAt = 1; itAt<=maxIt; itAt++)
    {
        if(itAt <= tam)
        {
            alfaAt = conjAlfa[itAt-1];
            nAlfa[itAt-1]++;
        }
        else
        {
            indice = probRandom(tam, prob);
            alfaAt = conjAlfa[indice];
            nAlfa[indice]++;
        }
        solAtual = algGulosoAleatoriedadeParam(alfaAt);
        valoresEncontrados[indice]+=solAtual->getTamanho();
        if(solAtual->getTamanho() > melhorSol->getTamanho())
            melhorSol = solAtual;
        if(itAt == 100*emBloco)
        {
            emBloco++;
            for(int i = 0; i<tam; i++)
            {

                if(nAlfa[i]!= 0)
                {
                    media[i] = (valoresEncontrados[i]*1.0)/nAlfa[i];
                    q[i] = (melhorSol->getTamanho()*1.0)/media[i];
                }
                else
                {
                    media[i] = 0.0;
                    q[i] = 0.0;
                }
            }
            somQ = 0.0;
            for(int i = 0; i<tam; i++)
                somQ = q[i] + somQ;
            for(int i = 0; i<tam; i++)
            {
                if(somQ!= 0.0)
                    prob[i] = (q[i]*1.0)/somQ;
                else
                    prob[i] = 0.0;
            }
        }
    }
    return melhorSol;
}
ListaDEncad* Grafo::algGulosoAleatoriedade500X(double alfa)
{
    ListaDEncad* melhorSol = new ListaDEncad();
    ListaDEncad* solAtual = new ListaDEncad();
    for(int i = 0; i<500; i++)
    {
        solAtual = algGulosoAleatoriedadeParam(alfa);
        if(melhorSol == NULL || melhorSol->getTamanho() < solAtual->getTamanho())
            melhorSol = solAtual;
    }
    return melhorSol;
}
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
}
