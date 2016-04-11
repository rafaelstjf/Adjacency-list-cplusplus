#ifndef CABECA_H_INCLUDED
#define CABECA_H_INCLUDED
#include "No.h"
class Cabeca
{
private:
    int idCabeca;
    No* ligacao;
    Cabeca* proxCabeca;
public:
    Cabeca();
    void atribIdCabeca(int val);
    void atribLigacao(No* p);
    void atribProx(Cabeca* c);
    int consultaId();
    No* consultaLigacao();
    Cabeca* consultaProxCabeca();
    ~Cabeca();
};


#endif // CABECA_H_INCLUDED
