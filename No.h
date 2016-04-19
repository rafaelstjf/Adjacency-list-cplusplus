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
    void atribIdNo(int val);
    void atribAresta(Bloco* p);
    void atribProx(No* c);
    void atribGrauNo(int grau);
    int consultarId();
    Bloco* consultarAresta();
    No* consultarProxNo();
    int consultarGrauNo();
    ~No();
};


#endif // NO_H_INCLUDED
