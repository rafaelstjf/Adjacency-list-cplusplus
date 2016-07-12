#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#define INF 100000
#include <sstream>
#include <string>
#include <iostream>
#include "No.h"
#include "ListaAdjacencia.h"
#include <stack>
#include "ListaDEncad.h"
#include <random>

class Grafo
{
private:
    No* prim; //ponteiro para o primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    No* ultimo;//ponteiro para o ultimo noh da lista
    int ordem;//ordem do grafo
    bool orientada;
    void inicio();
    void proximoNo();
    void procurarIdNo(int id);
    void adicionar(int ini, int fim, int peso);
    void limpaVisitados();
    bool bipartidoAux(No* n, int vertice[], int c);
    void componentesConexasAux(No* n, int cc, int* componentes);
    int* fechoTransitivoAux(int id);
    bool verificadorViabilidade(ListaDEncad* conjSolucao);
public:
    Grafo(bool tipo);
    void inserirNo(int val);
    bool existeIdNo(int id);
    bool grafoVazio();
    void adicionarAresta(int ini, int fim, int peso);
    string exibirGrafo();
    int grauNo(int vertice);
    int grauGrafo();
    bool verificarAdjacencia(int id1, int id2);
    string listarAdjacentesNo(int id);
    int ordemGrafo();
    int verificarKRegular();
    bool verificarGrafoCompleto();
    bool verificarGrafoConexo();
    void removerNo(int id);
    bool verificarGrafoBipartido();
    Grafo* grafoComplementar();
    Grafo* grafoInduzido(int tam, int vet[]);
    int contarComponentesConexas();
    bool verificarArestaPonte(int ini, int fim);
    bool verificarNoArticulacao(int id);
    string fechoTransitivoDireto(int id);
    string fechoTransitivoIndireto(int id);
    void removerAresta(int ini, int fim);
    Grafo* grafoTransposto();
    ListaDEncad* heuristica();
    ListaDEncad* algoritmoGuloso();
    ListaDEncad* algGulosoAleatoriedadeParam(double alfa);
    void algGulosoAleatoriedadeAuto(int tam,int conjAlfa[]);
    ~Grafo();//destrutor
};
#endif // GRAFO_H_INCLUDED
