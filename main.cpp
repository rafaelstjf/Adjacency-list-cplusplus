#include <iostream>
#include "ListaAdjacencia.h"
using namespace std;
void teste(){
int tamanho = 100;
char opcao = false;
ListaAdjacencia* lista = new ListaAdjacencia(opcao);
for(int i = 0; i<tamanho; i++){
lista->inserirUlt(i+1);
}
/*lista->adicionarAresta(1,1);
lista->adicionarAresta(1,1);
lista->adicionarAresta(1,4);
lista->adicionarAresta(1,3);
lista->adicionarAresta(1,2);*/
cout << "Grau no 1: "<< lista->grauNo(1);
cout << "Grau do grafo: " << lista->grauGrafo();
if(lista->verificarAdjacencia(1,7))
cout << "true"<< endl;
else cout << "false" << endl;
lista->listarAdjacentesNo(1);
if(lista->verificarKRegular() != -1)
cout << "O grafo eh "<< lista->verificarKRegular() << " regular!"<< endl;
delete lista;


}
int main()
{
    /*int qntVertices = 0;
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
    cout <<"Grau do no 6: " << lista->grauNo(6) << endl;
    cout << "Grau do grafo: " << lista->grauGrafo() <<endl;
delete lista;*/
teste();

    

}
