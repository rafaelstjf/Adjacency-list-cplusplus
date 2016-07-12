#ifndef BLOCO_H_INCLUDED
#define BLOCO_H_INCLUDED
#include <iostream>
class Bloco
{
private:
    Bloco* proximo;
    Bloco* anterior;
    int id;
    int grau;
public:
    Bloco();
    void setId(int i);
    void setGrau(int g);
    void setProximo(Bloco* p);
    void setAnterior(Bloco* a);
    int getId();
    int getGrau();
    Bloco* getProximo();
    Bloco* getAnterior();
    ~Bloco();
};
#endif // BLOCO_H_INCLUDED
