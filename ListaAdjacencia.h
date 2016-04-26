#ifndef LISTAADJACENCIA_H_INCLUDED
#define LISTAADJACENCIA_H_INCLUDED
#include "Bloco.h"//classe onde as ligacoes sao armazenadas
#include "No.h"//classe do No
class ListaAdjacencia
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    int tamanho;//tamanho da lista
    bool orientada;//caso true eh um digrafo caso false eh um grafo
    void adicionar(int ini, int fim);//adiciona um arco
public:
    ListaAdjacencia(bool tipo);//construtor
    //navegacao
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void inserirUlt(int val);//inserir um no no final da lista
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool listaVazia();//verifica se a lista esta vazia --prevencao de erros
    bool verificarAdjacencia(int id1, int id2);//verifica se os Nós são adjacentes
    int verificarKRegular();//dado um k verifica se o grafo eh k regular
    //manipulacao
    Bloco* criarBloco(int id, Bloco* prox);
    void adicionarAresta(int ini, int fim);//verifica o tipo de grafo e adiciona uma aresta/arco passando como parametros o vertice inicial e o final
   // void preencherGrafoCompleto();//preenche todas as arestas de maneira a criar o grafo completo
    //void imprimirLista();//imprimir a lista
    void listarAdjacentesNo(int id);//imprime os nós adjacentes ao Nó desejado
    int grauNo(int id);//retorna o grau do vertice
    int grauGrafo();//calcula o grau do grafo
    ~ListaAdjacencia();//destrutor
};


#endif // LISTAADJACENCIA_H_INCLUDED
