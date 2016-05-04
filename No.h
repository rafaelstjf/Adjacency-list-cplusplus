#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "ListaAdjacencia.h"
class No
{
private:
    int idNo, grauNo;
    ListaAdjacencia* arestas;
    No* proxNo;
    No* antNo;
    bool visitado;
public:
    No();
    void setIdNo(int val);//atribui um novo Id para o No
    void setArestas(ListaAdjacencia* p);//coloca o ponteiro aresta apontando para a primeira das ligações
    void setProx(No* c);//coloca o ponteiro proxNo apontando para um outro No
    void setGrauNo(int grau);//atribui um valor para o grau do No
    void setAntNo(No* a);//coloca o ponteiro antNo apontando para um outro no anterior
    void setVisitado(bool estado);//coloca o no como visitado ou nao visitado
    int getId();//consulta o Id do No
    ListaAdjacencia* getArestas();//Consulta o Bloco aresta
    No* getProxNo();//consulta o proximo No
    No* getAntNo();//consulta o No anterior
    bool getVisitado();//consulta o estado do no
    int getGrauNo();//consulta o grau do No
    ~No();
};
#endif // NO_H_INCLUDED
