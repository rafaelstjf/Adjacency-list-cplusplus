#include <iostream>
#include "ListaAdjacencia.h"
using namespace std;

int main()
{
    int qntVertices = 0;
    char opcao = ' ';
    ListaAdjacencia* lista;
    cout << "O grafo eh orientado? (y/n)" << endl;
    cin >> opcao;
    while(opcao != 'y' && opcao != 'n')
    {
        cout << "Opcao invalida! Digite y ou n" << endl;
        cin >> opcao;
    }
    if(opcao == 'y')
    {
        lista = new ListaAdjacencia(true);
    }
    else if (opcao == 'n')
    {
        lista = new ListaAdjacencia(false);
    }
    cout << "Digite a quantidade de vertices que deseja criar" << endl;
    cin >> qntVertices;

    for(int i = 0; i<qntVertices; i++)
    {
        lista->inserirUlt(i+1);
    }
    lista->imprimirLista();
    cout <<"Grau do no 6: " << lista->calcGrauNo(6) << endl;
    cout << "Grau do grafo: " << lista->calcGrauGrafo() <<endl;
    delete lista;

}
