#include <iostream>
#include "ListaAdjacencia.h"
using namespace std;

int main()
{
    int qntVertices = 0;
    ListaAdjacencia* lista = new ListaAdjacencia();
    cout << "digite a quantidade de vertices que deseja criar" << endl;
    cin >> qntVertices;
    for(int i = 0; i<qntVertices; i++)
    {
        lista->insereUlt(i+1);

    }
    lista->preencheGrafoCompleto();
    lista->procuraIdNo(7);
    /*lista->adicionaAresta(1,2);
    lista->adicionaAresta(1,2);
    lista->adicionaAresta(1,4);
    lista->adicionaAresta(1,4);
    lista->adicionaAresta(2,3);
    lista->adicionaAresta(2,3);*/
    lista->imprimeLista();
    cout <<"Grau: " << lista->calcGrauNo(6) << endl;
    delete lista;

}
