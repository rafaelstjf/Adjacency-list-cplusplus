#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "ListaAdjacencia.h"
class No
{
private:
    int idNo, grauNo;
    ListaAdjacencia* arestas;
    No* proxNo;
public:
    No();
    void setIdNo(int val);//atribui um novo Id para o No
    void setArestas(ListaAdjacencia* p);//coloca o ponteiro aresta apontando para a primeira das ligações
    void setProx(No* c);//coloca o ponteiro proxNo apontando para um outro No
    void setGrauNo(int grau);//atribui um valor para o grau do No
    int getId();//consulta o Id do No
    ListaAdjacencia* getArestas();//Consulta o Bloco aresta
    No* getProxNo();//consulta o proximo No
    int getGrauNo();//consulta o grau do No
    ~No();
};


#endif // NO_H_INCLUDED
