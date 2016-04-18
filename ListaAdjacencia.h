#ifndef LISTAADJACENCIA_H_INCLUDED
#define LISTAADJACENCIA_H_INCLUDED
#include "Bloco.h"
#include "No.h"
class ListaAdjacencia
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    int tamanho;
public:
    ListaAdjacencia();//construtor
    //navegacao
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void inserirUlt(int val);//inserir um no no final da lista
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool ListaVazia();//verifica se a lista esta vazia --prevencao de erros
    //manipulacao
    void adicionarAresta(int ini, int fim);//adicionar uma aresta/arco passando como parametros o vertice inicial e o final
    void preencherGrafoCompleto();//preencher todas as arestas de maneira a criar o grafo completo
    void imprimirLista();//imprimir a lista
    int calcGrauNo(int vertice);//calcula e retorna o grau do vertice
    int calcGrauGrafo();
    ~ListaAdjacencia();//destrutor
};


#endif // LISTAADJACENCIA_H_INCLUDED
