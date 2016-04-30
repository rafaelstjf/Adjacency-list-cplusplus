#include <iostream>
#include "Grafo.h"
using namespace std;
void teste()
{
    int tamanho = 5;
    char opcao = false;
    Grafo* grafo = new Grafo(opcao);
    for(int i = 0; i<tamanho; i++)
    {
        grafo->inserirNo(i+1);
    }
    /*Exemplo grafo conexo
    grafo->adicionarAresta(1,2);
    grafo->adicionarAresta(1,3);
    grafo->adicionarAresta(2,3);
    grafo->adicionarAresta(4,5);
    grafo->adicionarAresta(4,6);
    grafo->adicionarAresta(5,6);
    */
    /*Exemplo de grafo bipartido*/
    grafo->adicionarAresta(1,4);
    grafo->adicionarAresta(1,5);
    grafo->adicionarAresta(2,4);
    grafo->adicionarAresta(2,5);
    grafo->adicionarAresta(3,5);

    grafo->imprimirGrafo();
    // grafo->preencherGrafoCompleto();
    cout << "Grau no 1: "<< grafo->grauNo(1) << endl;
    cout << "Grau do grafo: " << grafo->grauGrafo() << endl;
    if(grafo->verificarAdjacencia(1,7))
        cout << "1 e 7 sao adjacentes"<< endl;
    else cout << "1 e 7 nao sao adjacentes" << endl;
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
    if(grafo->verificarGrafoBipartido())
        cout << "O grafo eh bipartido" << endl;
    else cout << "O grafo nao eh bipartido" << endl;

    delete grafo;


}
imprimirOpcoes(){
cout << "Opcao 1: Adicionar vertice" << endl;
cout << "Opcao 2: Adicionar aresta" << endl;

}
int main()
{
   cout << "Trabalho de Teoria dos Grafos" << endl;

}
