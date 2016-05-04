#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Grafo.h"
using namespace std;
std::fstream inputFile;
std::fstream outputFile;
void teste()
{
    int tamanho = 5;
    char opcao = false;
    Grafo* grafo = new Grafo(tamanho, opcao);
    /*grafo->adicionarAresta(1,4);
    grafo->adicionarAresta(1,5);
    grafo->adicionarAresta(2,4);
    grafo->adicionarAresta(2,5);
    grafo->adicionarAresta(3,5);*/
    grafo->preencherGrafoCompleto();
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
    if(grafo->verificarNoArticulacao(5))
        cout << "O vertice 1 eh de articulacao" << endl;
    else
        cout << "O vertice 1 nao eh de articulacao" << endl;
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
Grafo* preencherArestas(Grafo* g)
{
    string str;
    inputFile.clear(); //volta o estado para good
    inputFile.seekg(0, ios::beg); //volta ao inicio
    getline(inputFile, str);//pega a linha do arquivo
    char tempIni[5], tempFim[5];//vetor temporario
    int ini = 0, fim = 0, j = 0, contadorEspaco = 0;
    for(int k = 0; k<5; k++) //colocando null em todos os indices do vetor temporario
    {
        tempIni[k] = NULL;
        tempFim[k] = NULL;
    }
    while(inputFile.good())
    {
    for(int i =0; str[i]!= '\0';i++)
            str[i] = NULL;
        getline(inputFile, str);//pega a linha do arquivo
        for(int i = 0; str[i]!= '\0'; i++)
        {
            if(str[i] == ' ')
                contadorEspaco++;
            if(contadorEspaco == 0)
                tempIni[j] = str[i];
            if(contadorEspaco == 1 && ini == 0)
            {
                ini = atoi(tempIni);
                j = 0;
            }
            if(contadorEspaco == 1 && fim == 0)
                tempFim[j] = str[i];
            j++;
        }
        fim = atoi(tempFim);
        g->adicionarAresta(ini, fim);
        contadorEspaco = 0;
        fim = 0;
        ini = 0;
        j = 0;
        for(int k = 0; k<5; k++) //colocando null em todos os indices do vetor temporario
        {
            tempIni[k] = NULL;
            tempFim[k] = NULL;
        }
    }
    return g;
}
int main(int argc, char * argv [])
{
    Grafo* grafo = NULL;
    int tamanho  = 0, opcaoEscolhida = -1;
    int id = 0, ini = 0, fim = 0, tam = -1;
    int vet[tam];
    Grafo* gInduzido;
    Grafo* gComp;
    cout <<"\t\t\tTrabalho de Teoria dos grafos." << endl;
    if (argc == 3)
    {
        inputFile.open (argv[1], ios::in);//abre o arquivo
        outputFile.open(argv[2], ios::app);
        if(!inputFile) //verifica se o arquivo nao foi aberto
        {
            cerr << "Arquivo de entrada nao foi encontrado!" << endl;
            exit(-1);
        }
        if(!outputFile)
        {
            cerr << "Impossivel criar arquivo de saida!" << endl;
            exit(-1);
        }
    }
    else
    {
        cerr << "O algoritmo nao encontrou os arquivos de entrada ou saida!" << endl;
        exit(-1);
    }

    cout << "----------------------------------"<< endl;
    cout << "Criando grafo a partir do arquivo. "<< endl;
    tamanho = obterTamanhoGrafo();
    grafo = new Grafo(tamanho, false);
    grafo = preencherArestas(grafo);
    cout << "Grafo criado com sucesso!" << endl;
    cout << "----------------------------------"<< endl;
    menu();
    while(opcaoEscolhida<1 || opcaoEscolhida>14)
    {
        cin >> opcaoEscolhida;
        if(opcaoEscolhida<1 || opcaoEscolhida>14)
            cout << "Opcao invalida! digite novamente." << endl;
    }

    switch (opcaoEscolhida)
    {
    case 1:
        cout << "Exibindo grafo." <<endl;
        grafo->exibirGrafo();
        break;
    case 2:
        cout << "Digite o vertice desejado." << endl;
        cin >> id;
        while(id < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> id;
        }
        cout << " O grau do vertice " << id << " eh: " << grafo->grauNo(id) << endl;
        break;
    case 3:
        cout << "O grau do grafo eh: " << grafo->grauGrafo();
        break;
    case 4:
        cout << "Digite o vertice desejado." << endl;
        cin >> id;
        while(id < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> id;
        }
        grafo->listarAdjacentesNo(id);
        break;
    case 5:
        if(grafo->verificarKRegular()== -1)
            cout << "O grafo nao eh K-regular." << endl;
        else
            cout << "O grafo eh "<<grafo->verificarKRegular() <<"-regular." << endl;
        break;
    case 6:
        if(grafo->verificarGrafoCompleto())
            cout << "O grafo eh completo." << endl;
        else
            cout << "O grafo nao eh completo." << endl;
        break;
    case 7:
        if(grafo->verificarGrafoConexo())
            cout << "O grafo eh conexo." << endl;
        else
            cout << "O grafo nao eh conexo." << endl;
        break;
    case 8:
        if(grafo->verificarGrafoBipartido())
            cout << "O grafo eh bipartido." << endl;
        else
            cout << "O grafo nao eh bipartido." << endl;
        break;
    case 9:
        cout << "Digite o tamanho do conjunto de vertices." << endl;
        tam = -1;
        while(tam < 0)
        {
            cin >> tam;
            if(tam<0)
                cout << "Tamanho invalido! Digite novamente." << endl;
        }

        for(int i = 0; i<tam; i++)
        {
            cout << "Digite o vertice." << endl;
            cin >> vet[i];
            while(vet[i] < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> vet[i];
            }
        }
        gInduzido  = grafo->grafoInduzido(tam, vet);
        gInduzido->exibirGrafo();
        break;
    case 10:
        cout << "Digite o vertice desejado." << endl;
        cin >> id;
        while(id < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> id;
        }
        if(grafo->verificarNoArticulacao(id))
            cout << "O vertice "<< id <<" eh de articulacao." << endl;
        else
            cout << "O vertice "<< id <<" nao eh de articulacao." << endl;
        break;
    case 11:
        gComp = grafo->grafoComplementar();
        gComp->exibirGrafo();
        break;
    case 12:
        cout << "Digite o vertice inicial." << endl;
        ini =0;
        cin >> ini;
        while(ini < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> ini;
        }
        cout << "Digite o vertice final" << endl;
        fim =0;
        cin >> fim;
        while(fim < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> fim;
        }
        if(grafo->verificarArestaPonte(ini, fim))
            cout << "A aresta (" << ini << "," << fim << ") eh de articulacao." << endl;
        else
            cout << "A aresta (" << ini << "," << fim << ") nao eh de articulacao." << endl;
        break;
    case 13:
        cout << "Digite o primeiro vertice." << endl;
        ini =0;
        cin >> ini;
        while(ini < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> ini;
        }
        cout << "Digite o segundo vertice." << endl;
        fim =0;
        cin >> fim;
        while(fim < 0)
        {
            cout << "Vertice invalido! Digite novamente." << endl;
            cin >> fim;
        }
        if(grafo->verificarAdjacencia(ini, fim))
            cout << "Os vertices (" << ini << "," << fim << ") sao adjacentes." << endl;
        else
            cout << "Os vertices (" << ini << "," << fim << ") nao sao adjacentes." << endl;
        break;
    case 14:
        exit(0);
        break;

    default:
        exit(0);
    }

}
/*Codigos dos erros
    -1 = erro na abertura dos arquivos
*/
