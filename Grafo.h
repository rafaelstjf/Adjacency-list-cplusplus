#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Bloco.h"//classe onde as ligacoes sao armazenadas
#include "No.h"//classe do No
class Grafo
{
private:
    No* prim; //primeiro no da lista
    No* aux; //ponteiro auxiliar para navegacao na lista
    int tamanho;//tamanho da lista
    bool orientada;//caso true eh um digrafo caso false eh um grafo
    void adicionar(int ini, int fim);//adiciona um arco
    Bloco* criarBloco(int id, Bloco* prox);//cria um novo bloco
    void inicio(); //coloca aux apontando para a primeiro no
    void proximoNo();//avanca o ponteiro aux para a proximo no
    void inserirNo(int val);//inserir um no no final da lista
    void procurarIdNo(int id);//redireciona o aux para o no com o id desejado
public:
    Grafo(bool tipo);//construtor
    //navegacao
    bool existeIdNo(int id);//verifica se existe o no do id desejado
    bool listaVazia();//verifica se a lista esta vazia --prevencao de erros
    //manipulacao
    void adicionarAresta(int ini, int fim);//verifica o tipo de grafo e adiciona uma aresta/arco passando como parametros o vertice inicial e o final
    void preencherGrafoCompleto();//preenche todas as arestas de maneira a criar o grafo completo
    void imprimirGrafo();//imprimir a lista
    bool verificarAdjacencia(int id1, int id2);//verifica se os Nós são adjacentes
    bool verificarGrafoConexo();//verifica se o grafo eh conexo
    bool verificarGrafoBipartido();//verifica se o grafo eh bipartido
    int verificarKRegular();//verifica se o grafo eh k regular
    bool verificarGrafoCompleto();//verifica se um grafo eh completo
    bool verificarVerticeArticulacao(int id);//verifica se um dado vertice eh de articulacao
    void listarAdjacentesNo(int id);//imprime os nós adjacentes ao Nó desejado
    int grauNo(int id);//retorna o grau do vertice
    int grauGrafo();//calcula o grau do grafo
    int ordemGrafo();//retorna a ordem do grafo
    ~Grafo();//destrutor
};


#endif // GRAFO_H_INCLUDED
