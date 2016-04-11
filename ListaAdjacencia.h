#ifndef LISTAADJACENCIA_H_INCLUDED
#define LISTAADJACENCIA_H_INCLUDED
#include "No.h"
#include "Cabeca.h"
class ListaAdjacencia
{
private:
    Cabeca* prim; //primeira cabeca da lista
    Cabeca* aux; //ponteiro auxiliar para navegacao na lista
public:
    ListaAdjacencia();//construtor
    void inicio(); //coloca aux apontando para a primeira cabeca
    void proximaCabeca();//avanca o ponteiro aux para a proxima cabeca
    void inserePri(int val);//insere uma cabeca na posicao inicial da lista
    void insereUlt(int val);//insere uma cabeca no final da lista
    void adicionarLigacao(int ini, int fim);
    void imprimeLista();//imprime a lista
    ~ListaAdjacencia();//destrutor
};


#endif // LISTAADJACENCIA_H_INCLUDED
