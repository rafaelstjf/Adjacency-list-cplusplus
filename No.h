#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "Bloco.h"
class No
{
private:
    int idNo, grauNo;
    Bloco* aresta;
    No* proxNo;
public:
    No();
    void atribIdNo(int val);//atribui um novo Id para o No
    void atribAresta(Bloco* p);//coloca o ponteiro aresta apontando para a primeira das ligações
    void atribProx(No* c);//coloca o ponteiro proxNo apontando para um outro No
    void atribGrauNo(int grau);//atribui um valor para o grau do No
    int consultarId();//consulta o Id do No
    Bloco* consultarAresta();//Consulta o Bloco aresta
    No* consultarProxNo();//consulta o proximo No
    int consultarGrauNo();//consulta o grau do No
    ~No();
};


#endif // NO_H_INCLUDED
