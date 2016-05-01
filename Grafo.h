#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
class Grafo
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    No* ultimo;
    int tamanho;
    bool orientada;//caso true eh um digrafo caso false eh um grafo
    void adicionarArco(int ini, int fim);//adiciona um arco
    bool verificarNoArticulacaoAux(Grafo* g, int id);//funcao auxiliar
    Grafo* clonarGrafo();//faz uma copia do grafo atual
public:
    Grafo(bool tipo);//construtor
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void inserirNo(int val);//inserir um no no final da lista
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool grafoVazio();//verifica se a lista esta vazia --prevencao de erros
    void adicionarAresta(int ini, int fim);//verifica o tipo de grafo e adiciona uma aresta/arco passando como parametros o vertice inicial e o final
    void preencherGrafoCompleto();//preencher todas as arestas de maneira a criar o grafo completo
    void imprimirGrafo();//imprimir a lista
    int grauNo(int vertice);//calcula e retorna o grau do vertice
    int grauGrafo();//calcula e retorna o grau do grafo
    bool verificarAdjacencia(int id1, int id2);//verifica se os Nós são adjacentes
    void listarAdjacentesNo(int id);//imprime os adjacentes do No de Id desejado
    int ordemGrafo(); // retorna a ordem do grafo (numero de nos)
    int verificarKRegular();//verifica se o grafo eh k regular
    bool verificarGrafoCompleto();//verifica se um grafo eh completo
    bool verificarGrafoConexo();//verifica se o grafo eh conexo
    void removerNo(int id);//remove um determinado no
    bool verificarNoArticulacao(int id);//verifica se um dado no eh de articulacao
    bool verificarGrafoBipartido(); //verifica se o grafo eh bipartido

    ~Grafo();//destrutor
};
#endif // GRAFO_H_INCLUDED
