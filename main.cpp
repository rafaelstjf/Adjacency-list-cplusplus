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
        lista->inserirUlt(i+1);
    }
    lista->preencherGrafoCompleto();
    lista->imprimirLista();
    cout <<"Grau do no 6: " << lista->calcGrauNo(6) << endl;
    delete lista;

}
