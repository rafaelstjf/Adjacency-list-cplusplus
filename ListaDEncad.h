#ifndef LISTADENCAD_H_INCLUDED
#define LISTADENCAD_H_INCLUDED
#include"Bloco.h"
#include<iostream>
class ListaDEncad
{
private:
    Bloco* pri;
    Bloco* ult;
    Bloco* it;
    int tamanho;
    int semente;
    double alfa;
public:
    ListaDEncad();
    void inicio();
    void inserirOrdGrau(int id, int grau);
    bool listaVazia();
    bool existeId(int id);
    void removerId(int id);
    void proxBloco();
    void procurarId(int id);
    int getTamanho();
    int getSemente();
    void setSemente(int s);
    void setAlfa(double a);
    double getAlfa();
    Bloco* getIt();
    ~ListaDEncad();
};
#endif // LISTADENCAD_H_INCLUDED
