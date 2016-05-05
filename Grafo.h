#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <sstream>
#include<string>
#include <iostream>
#include "No.h"
#include "ListaAdjacencia.h"
#include<stack>
class Grafo
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    No* ultimo;
    int ordem;
    bool orientada;//caso true eh um digrafo caso false eh um grafo
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
    void adicionarArco(int ini, int fim);//adiciona um arco
    void limpaVisitados();//coloca todos os nos como nao visitados
    bool bipartidoAux(No* n, int vertice[], int c);//funcao auxiliar da verificarGrafoBipartido
    void componentesConexasAux(No* n, int cc, int* componentes);
public:
    Grafo(bool tipo);//construtor
    void inserirNo(int val);//inserir um no no final da lista
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool grafoVazio();//verifica se a lista esta vazia --prevencao de erros
    void adicionarAresta(int ini, int fim);//verifica o tipo de grafo e adiciona uma aresta/arco passando como parametros o vertice inicial e o final
    void preencherGrafoCompleto();//preencher todas as arestas de maneira a criar o grafo completo
    string exibirGrafo();//exibe a o grafo em forma de lista de adjacencia
    int grauNo(int vertice);//calcula e retorna o grau do vertice
    int grauGrafo();//calcula e retorna o grau do grafo
    bool verificarAdjacencia(int id1, int id2);//verifica se os Nós são adjacentes
    string listarAdjacentesNo(int id);//imprime os adjacentes do No de Id desejado
    int ordemGrafo(); // retorna a ordem do grafo (numero de nos)
    int verificarKRegular();//verifica se o grafo eh k regular
    bool verificarGrafoCompleto();//verifica se um grafo eh completo
    bool verificarGrafoConexo();//verifica se o grafo eh conexo
    void removerNo(int id);//remove um determinado no
    bool verificarNoArticulacao(int id);//verifica se um dado no eh de articulacao
    bool verificarGrafoBipartido(); //verifica se o grafo eh bipartido
    bool verificarArestaPonte(int ini, int fim);//verifica se a aresta desejada eh uma ponte
    Grafo* grafoComplementar();//retorna o grafo complementar
    Grafo* grafoInduzido(int tam, int vet[]);//retorna o grafo induzido
    int contarComponentesConexas();

    ~Grafo();//destrutor
};
#endif // GRAFO_H_INCLUDED
