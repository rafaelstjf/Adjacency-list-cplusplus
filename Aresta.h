#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include <iostream>
using namespace std;
class Aresta
{
private:
    int id; //ID do bloco
    Aresta* proximo; //ponteiro para o proximo bloco
    Aresta* anterior;
    int peso;
public:
    Aresta();
    int getId();
    Aresta* getProx();
    Aresta* getAnterior();
    int getPeso();
    void setId(int id);
    void setPeso(int pe);
    void setAnterior(Aresta* c);
    void setProx(Aresta* p);
    ~Aresta();
};
#endif // ARESTA_H_INCLUDED
