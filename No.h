#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
class No
{
private:
    float info; // informacao real do No
    No* prox; //ponteiro para o proximo No
public:
    No();
    float consultaInfo();
    No* consultaProx();
    void atribInfo(float val);
    void atribProx(No *p);
    ~No();
};


#endif // NO_H_INCLUDED
