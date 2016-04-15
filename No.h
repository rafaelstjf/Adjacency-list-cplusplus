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
    int consultarId();
    Bloco* consultarAresta();
    No* consultarProxNo();
    ~No();
};


#endif // NO_H_INCLUDED
