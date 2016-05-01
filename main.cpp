#include <iostream>
#include "Grafo.h"
using namespace std;
void teste()
{
    int tamanho = 6;
    char opcao = false;
    Grafo* grafo = new Grafo(opcao);
    for(int i = 0; i<tamanho; i++)
    {
        grafo->inserirNo(i+1);
    }
    grafo->adicionarAresta(1,2);
    grafo->adicionarAresta(1,3);
    grafo->adicionarAresta(1,4);
    grafo->adicionarAresta(2,3);
    grafo->adicionarAresta(4,5);
    grafo->adicionarAresta(4,6);
    grafo->adicionarAresta(5,6);
    grafo->imprimirGrafo();
    //grafo->preencherGrafoCompleto();
    cout << "Grau no 1: "<< grafo->grauNo(1) << endl;
    cout << "Grau do grafo: " << grafo->grauGrafo() << endl;
    if(grafo->verificarAdjacencia(2,3))
        cout << "1 e 3 sao adjacentes"<< endl;
    else cout << "1 e 3 nao sao adjacentes" << endl;
    grafo->listarAdjacentesNo(1);
    if(grafo->verificarGrafoCompleto() == true)
        cout << "O grafo eh completo" << endl;
    else
        cout << "O grafo nao eh completo" << endl;
    if(grafo->verificarKRegular() != -1)
        cout << "O grafo eh "<< grafo->verificarKRegular() << " regular!"<< endl;
    else
        cout << "O grafo nao eh K-regular!" << endl;
    if(grafo->verificarGrafoConexo())
        cout << "O grafo eh conexo" << endl;
    else cout << "O grafo nao eh conexo" << endl;
    grafo->removerNo(3);
    grafo->imprimirGrafo();
}
int main()
{
    teste();
}
