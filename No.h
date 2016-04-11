#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
class No
{
private:
    int id; //ID do nó
    No* proximo; //ponteiro para o proximo no
public:
    No();
    int consultaId();
    No* consultaProx();
    void atribId(int id);
    void atribProx(No* p);
    ~No();
};


#endif // NO_H_INCLUDED
