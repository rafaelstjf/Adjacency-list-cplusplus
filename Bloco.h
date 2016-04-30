#ifndef BLOCO_H_INCLUDED
#define BLOCO_H_INCLUDED
class Bloco//classe aonde sao armazenadas as ligacoes
{
private:
    int id; //ID do bloco
    Bloco* proximo; //ponteiro para o proximo bloco
public:
    Bloco();//construtor
    int consultarId();//consulta o Id do bloco
    Bloco* consultarProx();//consulta o proximo bloco
    void atribId(int id);//atribui um Id ao bloco
    void atribProx(Bloco* p);//atribui um novo bloco para o ponteiro proximo
    ~Bloco();//destrutor
};


#endif // BLOCO_H_INCLUDED
