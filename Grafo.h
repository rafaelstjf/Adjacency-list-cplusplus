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
    No* prim; //ponteiro para o primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    No* ultimo;//ponteiro para o ultimo noh da lista
    int ordem;//ordem do grafo
    bool orientada;//caso true é um digrafo caso false é um grafo
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
    void adicionarArco(int ini, int fim, int peso);//adiciona um arco
    void limpaVisitados();//coloca todos os nos como nao visitados
    bool bipartidoAux(No* n, int vertice[], int c);//funcao auxiliar da verificarGrafoBipartido
    void componentesConexasAux(No* n, int cc, int* componentes);//funcao auxiliar da contarComponentes conexas
    int* fechoTransitivoAux(int id);// auxiliar para as funcoes de fecho transitivo direto e indireto
public:
    Grafo(bool tipo);//construtor
    void inserirNo(int val); //insere um novo No ordenado no fim da lista
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool grafoVazio();//verifica se a lista esta vazia --prevencao de erros
    void adicionarAresta(int ini, int fim, int peso);//verifica o tipo de grafo e adiciona uma aresta/arco passando como parametros o vertice inicial e o final
    string exibirGrafo();//retorna uma string como grafo em forma de lista de adjacencia
    int grauNo(int vertice);//retorna o grau do vertice desejado
    int grauGrafo();//calcula e retorna o grau do grafo
    bool verificarAdjacencia(int id1, int id2);//verifica se os Nós são adjacentes
    string listarAdjacentesNo(int id);//retorna uma string com os adjacentes do No de Id desejado
    int ordemGrafo(); // retorna a ordem do grafo (numero de nos)
    int verificarKRegular();//verifica se o grafo é k regular caso seja, retorna o valor de K
    bool verificarGrafoCompleto();//verifica se um grafo é completo
    bool verificarGrafoConexo();//verifica se o grafo é conexo
    void removerNo(int id);//remove um determinado no
    bool verificarGrafoBipartido(); //verifica se o grafo é bipartido
    Grafo* grafoComplementar();//retorna o grafo complementar
    Grafo* grafoInduzido(int tam, int vet[]);//retorna o grafo induzido
    int contarComponentesConexas();//retorna o numero de componentes conexas
    bool verificarArestaPonte(int ini, int fim);//verifica se a aresta desejada é uma ponte
    bool verificarNoArticulacao(int id);//verifica se um dado no é de articulacao
    string fechoTransitivoDireto(int id);//exibe o conjunto de vertices que podem ser acessados por um caminho no vertice de id desejado
    string fechoTransitivoIndireto(int id);//exibe o conjunto de vertices que acessam por algum caminho o vertice de id desejado
    void removerAresta(int ini, int fim);//remove a aresta entre os vertices desejados
    Grafo* grafoTransposto();//retorna o grafo transposto
    void algoritmoPrim();
    ~Grafo();//destrutor
};
#endif // GRAFO_H_INCLUDED
