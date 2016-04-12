#ifndef LISTAADJACENCIA_H_INCLUDED
#define LISTAADJACENCIA_H_INCLUDED
#include "Bloco.h"
#include "No.h"
class ListaAdjacencia
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
public:
    ListaAdjacencia();//construtor
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void inserePri(int val);//insere um no na posicao inicial da lista
    void insereUlt(int val);//insere um no no final da lista
    void adicionaAresta(int ini, int fim);//adiciona uma aresta/arco passando como parametros o vertice inicial e o final
    void procuraIdNo(int id);//redireciona o aux para o no com o id desejado
    bool existeIdNo(int id);
    void imprimeLista();//imprime a lista
    int  calcGrauNo(int vertice);//calcula e retorna o grau do vertice
    ~ListaAdjacencia();//destrutor
};


#endif // LISTAADJACENCIA_H_INCLUDED
