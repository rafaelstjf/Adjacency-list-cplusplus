#ifndef TLISTASENCAD_H_INCLUDED
#define TLISTASENCAD_H_INCLUDED
#include "No.h"
class TListaSEncad
{
private:
    No *pri;
    No *it; //ponteiro auxiliar para percorrer a lista
public:
    TListaSEncad();
    float Consulta();
    void Atribui(float val);
    bool Busca(float val);
    void Inicio(); //coloca o pont it no inicio
    void ProximoNo(); //avanca o ponteiro it
    bool FimDaLista(); //verifica se it esta no final
    void InserePri(float val);
    void InsereK(float val);
    void InsereUltimo(float val);
    void EliminaPri();
    void EliminaK();
    void EliminaUltimo();
    ~TListaSEncad();

};


#endif // TLISTASENCAD_H_INCLUDED
