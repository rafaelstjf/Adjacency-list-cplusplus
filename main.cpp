#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Grafo.h"
using namespace std;
std::ifstream inputFile;
void teste()
{
    int tamanho = 6;
    char opcao = false;
    Grafo* grafo = new Grafo(tamanho, opcao);
   grafo->adicionarAresta(1,4);
    grafo->adicionarAresta(1,5);
    grafo->adicionarAresta(2,4);
    grafo->adicionarAresta(2,5);
    grafo->adicionarAresta(3,5);
  // grafo->preencherGrafoCompleto();
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
   /* if(grafo->verificarNoArticulacao(6))
      cout << "O vertice 1 eh de articulacao" << endl;
     else
     cout << "O vertice 1 nao eh de articulacao" << endl;*/
     if(grafo->verificarGrafoBipartido())
    cout << "o grafo eh bipartido" << endl;
    else
        cout << "O grafo nao eh bipartido" << endl;
        grafo->exibirGrafo();
        cout << "grafo complementar" << endl;
    Grafo* g = grafo->grafoComplementar();
    g->exibirGrafo();
    cout << "-------------------------------" << endl;
    int vet[3] = {1,2,3};
    Grafo* gU = grafo->grafoInduzido(3, vet);
    gU->exibirGrafo();
}
void menu()
{
    cout << "Funcionalidades: " <<endl;
    cout << " 1 - Exibir o grafo." << endl;
    cout << " 2 - Retornar o grau do vertice desejado." << endl;
    cout << " 3 - Retornar o grau do grafo." << endl;
    cout << " 4 - Listar os adjacentes de um determinado vertice." << endl;
    cout << " 5 - Verificar se o grafo eh K-regular." << endl;
    cout << " 6 - Verificar se o grafo eh completo." << endl;
    cout << " 7 - Verificar se o grafo eh conexo." << endl;
    cout << " 8 - Verificar se o grafo eh bipartido." << endl;
    cout << " 9 - Dado um conjunto X de vertices, retornar o grafo induzido." << endl;
    cout << "10 - Verificar se um dado vertice eh de articulacao." << endl;
    cout << "11 - Retornar o grafo complementar." << endl;
    cout << "12 - Verificar se uma dada aresta eh ponte." << endl;
    cout << "13 - Verificar se dois vertices sao adjacentes." << endl;
    cout << "14 - Sair." << endl;
}
void opcao1() {}
void opcao2() {}
void opcao3() {}
void opcao4() {}
void opcao5() {}
void opcao6() {}
void opcao7() {}
void opcao8() {}
void opcao9() {}
void opcao10() {}
void opcao11() {}
void opcao12() {}
void opcao13() {}
void opcao14() {}
int obterTamanhoGrafo()
{
    string str;
    inputFile.clear(); //volta o estado para good
    inputFile.seekg(0, ios::beg); //volta ao inicio
    char temporaria[10];//vetor temporario
    int tamanho = 0, i = 0, j = 0;
    for(int k = 0; k<10; k++)//colocando null em todos os indices do vetor temporario
        temporaria[i] = NULL;
    getline(inputFile, str);//pega a primeira linha do arquivo
    while (str[i] != '\0') //enquanto nao chega ao fim do string
    {
        if(str[i] == ' ' || str[i + 1] == '\0')//verifica se o caractere eh o espaco ou o final da linha
        {
            //limpa os numeros apos a parada
            if( str[i + 1] == '\0')
            {
                temporaria[j] = str[i];
                j++;
            }
            for (int limp = j; temporaria[limp] != '\0'; limp++)
                temporaria[limp] = NULL;
            //converte o vetor char em int
            tamanho = atoi(temporaria);
            j = 0;//volta o indice do vetor temporario para 0
        }
        else if (str[i] != ' ' || str[i + 1] != '\0')//for para passar os valores da string para o vetor char
        {
            temporaria[j] = str[i];
            j++;
        }
        i++;//aumenta o indice da string
    }
    return tamanho;
}
int main(int argc, char * argv [])
{
    //Grafo* grafo;
    //int tamanho  = 0, opcaoEscolhida = -1;
    //cout <<"\t\t\tTrabalho de Teoria dos grafos." << endl;
    teste();
    /*if (argc == 3)
    {
        inputFile.open (argv[1], std::ofstream::in);//abre o arquivo
        if(!inputFile) //verifica se o arquivo nao foi aberto
        {
            cerr << argv[1] << " nao foi encontrado!" << endl;
            exit(-1);
        }
    }
    else
    {
        cerr << "O algoritmo nao encontrou os arquivos de entrada ou saida!" << endl;
        exit(-1);
    }*/

    /*cout << "----------------------------------"<< endl;
    cout << "Criando grafo a partir do arquivo. "<< endl;
    inputFile.open("grafo_125.txt", std::ifstream::in);
    tamanho = obterTamanhoGrafo();
    grafo = new Grafo(tamanho, false);
    cout << "Grafo criado com sucesso!" << endl;
    cout << "----------------------------------"<< endl;
    menu();*/

    return 0;
}
/*Codigos dos erros
    -1 = erro na leitura dos arquivos
*/
