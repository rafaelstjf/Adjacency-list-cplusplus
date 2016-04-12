#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "Bloco.h"
class No
{
private:
    int idNo;
    Bloco* aresta;
    No* proxNo;
public:
    No();
    void atribIdNo(int val);
    void atribAresta(Bloco* p);
    void atribProx(No* c);
    int consultaId();
    Bloco* consultaAresta();
    No* consultaProxNo();
    ~No();
};


#endif // NO_H_INCLUDED
