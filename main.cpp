#include <iostream>
#include "TListaSEncad.h"
using namespace std;
void imprime(TListaSEncad* l)
{
    l->Inicio();
    while(!l->FimDaLista())
    {
        cout << l->Consulta() << endl;
        l->ProximoNo();
    }
}
int main()
{
    //criando a lista
    cout << "Criando a Lista" << endl;
    float val;
    TListaSEncad* lista = new TListaSEncad();
    for(int i = 0; i<5; i++)
    {
        val = i;
        lista->InserePri(val);
    }
    lista->Inicio();
    imprime(lista);

    //testando o insere k
    cout << "Testando o InsereK e InsereUltimo" << endl;
    lista->Inicio();
    if(!lista->FimDaLista())
    {
        lista->ProximoNo();
        lista->ProximoNo();
    }
    lista->InsereK(3.5);

    //testando insere ultimo
    lista->InsereUltimo(10.9);
    lista->Inicio();
    cout << endl;
    imprime(lista);

    //testando elimina k
    cout << "Testando EliminaK" << endl;
    cout << endl;
    lista->Inicio();
    if(!lista->FimDaLista())
    {
        lista->ProximoNo();
        lista->ProximoNo();
    }
    lista->EliminaK();
    lista->Inicio();
    cout << endl;
    imprime(lista);

    //testando EliminaUltimo
    cout << "Testando EliminaUltimo" << endl;
    lista->EliminaUltimo();
    imprime(lista);
    cout << "Deletando a lista..." << endl;

    delete lista;
    return 0;
}
