#ifndef BLOCO_H_INCLUDED
#define BLOCO_H_INCLUDED
class Bloco
{
private:
    int id; //ID do bloco
    Bloco* proximo; //ponteiro para o proximo bloco
public:
    Bloco();
    int consultaId();
    Bloco* consultaProx();
    void atribId(int id);
    void atribProx(Bloco* p);
    ~Bloco();
};


#endif // BLOCO_H_INCLUDED
