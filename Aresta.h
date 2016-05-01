#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
class Aresta
{
private:
    int id; //ID do bloco
    Aresta* proximo; //ponteiro para o proximo bloco
	Aresta* anterior;
public:
    Aresta();
    int getId();
    Aresta* getProx();
    void setId(int id);
	Aresta* getAnterior();
    void setAnterior(Aresta* c);
    void setProx(Aresta* p);
    ~Aresta();
};
#endif // ARESTA_H_INCLUDED
