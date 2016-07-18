#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <random>
#include "Grafo.h"
using namespace std;
std::fstream inputFile;
std::fstream outputFile;
void menu()
{
    cout << "Funcionalidades: " <<endl;
    cout << " 0 - Ajuda." << endl;
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
    cout << "14 - Adicionar aresta/arco" << endl;
    cout << "15 - Adicionar vertice" << endl;
    cout << "16 - Remover aresta/arco" << endl;
    cout << "17 - Remover vertice" << endl;
    cout << "18 - Fecho transitivo direto(fechado) de um vertice." << endl;
    cout << "19 - Fecho transitivo indireto(fechado) de um vertice." << endl;
    cout << "20 - Exibir o grafo transposto." << endl;
    cout << "21 - Algoritmo construtivo guloso para o conjunto independente maximo (MIS)." << endl;
    cout << "22 - Algoritmo construtivo guloso com aleatoriedade passada como parametro." << endl;
    cout << "23 - Algoritmo construtivo guloso com aleatoriedade ajustada automaticamente." << endl;
    cout << "24 - Sair." << endl;
}
Grafo* gerarGrafo()
{
//obter tamanho do grafo
    string str;
    char temporaria[10], tempIni[8], tempFim[8], tempPeso[8];//vetores temporarios
    char opcao = '\0';
    bool orientado = false;
    int ini = 0, fim = 0, j = 0,peso = 0, contadorEspaco = 0, tamanho = 0, i = 0;
    for(int k = 0; k<10; k++)//zerando o vetor de char
        temporaria[k] = '\0';
    inputFile.clear(); //volta o estado para good
    inputFile.seekg(0, ios::beg); //volta ao inicio
    getline(inputFile, str);//pega a primeira linha do arquivo
    while (str[i] != '\0') //enquanto nao chega ao fim do string
    {
        if(str[i] == 32 || str[i + 1] == '\0')//verifica se o caractere é o espaco ou o final da linha
        {
            //limpa os numeros apos a parada
            if( str[i + 1] == '\0')
            {
                temporaria[j] = str[i];
                j++;
            }

            //converte o vetor char em int
            tamanho = atoi(temporaria);
            for (int ultN = j; temporaria[ultN] != '\0'; ultN++)//verifica se n tem mais numeros depois de J
                temporaria[ultN] = '\0';
            j = 0;//volta o indice do vetor temporario para 0
        }
        else if (str[i] != 32 || str[i + 1] != '\0')//for para passar os valores da string para o vetor char
        {
            temporaria[j] = str[i];
            j++;
        }
        i++;//aumenta o indice da string
    }
    // preencher e verificar se eh orientada
    cout << "O grafo eh orientado? [S/N]" << endl;
    cin >> opcao;
    while(opcao!='S' && opcao!='N')
    {
        cout << "Opcao errada! Digite S ou N." << endl;
        cin >> opcao;
    }
    if(opcao=='S')
        orientado = true;
    else if(opcao == 'N')
        orientado = false;
    Grafo* g = new Grafo(orientado);
    for(int t = 0; t<tamanho; t++)
        g->inserirNo(t);
    for(int k = 0; k<8; k++) //colocando null em todos os indices do vetor temporario
    {
        tempIni[k] = '\0';
        tempFim[k] = '\0';
        tempPeso[k] = '\0';
    }
    j = 0;
    while(inputFile.good())
    {
        getline(inputFile, str);//pega a linha do arquivo
        for(int t = 0; str[t]!= '\0'; t++)
        {
            if(str[t] == 32)
                contadorEspaco++;
            if(contadorEspaco == 0)
                tempIni[j] = str[t];
            if(contadorEspaco == 1 && ini == 0)
            {
                ini = atoi(tempIni);
                j = 0;
            }
            if(contadorEspaco == 1)
                tempFim[j] = str[t];
            if(contadorEspaco == 2 && fim == 0)
            {
                fim = atoi(tempFim);
                j = 0;
            }

            if(contadorEspaco == 2)
            {
                tempPeso[j] = str[t];
            }

            j++;
        }
        if(contadorEspaco==1)
            fim = atoi(tempFim);
        peso = atoi(tempPeso);
        g->adicionarAresta(ini, fim,peso);
        contadorEspaco = 0;
        fim = 0;
        ini = 0;
        peso = 0;
        j = 0;
        for(int k = 0; k<8; k++) //cotocando null em todos os indices do vetor temporario
        {
            tempIni[k] = '\0';
            tempFim[k] = '\0';
            tempPeso[k] = '\0';
        }
    }
    return g;
}
bool desejaSalvar()
{
    char op = '\0';
    cout << "Deseja salvar em arquivo? [S/N]" << endl;
    cin >> op;
    while(op!='S' && op!= 'N')
    {
        cout << "opcao invalida! Digite novamente" << endl;
        cin >> op;
    }
    if(op == 'S')
        return true;
    else if(op == 'S')
        return false;
}
void limparTela()
{
#ifdef LINUX
    system("clear");
#endif // LINUX
#ifdef _WIN32
    system("cls");
#endif // WIN32
}
int main(int argc, char * argv [])
{
    Grafo* grafo = NULL;
    int tamanho  = 0, opcaoEscolhida = -1;
    int id = 0, ini = 0, fim = 0, tam = -1, peso = -1, seed = 0;
    double alfa = 0;
    char help = '\0';
    int vet[tam];
    double vetorAlfas[tam];
    Grafo* gComp = NULL;
    Grafo* gInduzido = NULL;
    Grafo* gTransp = NULL;
    ListaDEncad* conjSolucaoGuloso = new ListaDEncad();
    if (argc == 3)
    {
        inputFile.open (argv[1], ios::in);//abre o arquivo
        outputFile.open(argv[2], ios::out);
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
    cout <<"\t\t\tTrabalho de Teoria dos grafos." << endl;
    cout << "\t\tAluno: Rafael de Souza Terra - 201465581C" << endl;
    outputFile <<"\t\t\tTrabalho de Teoria dos grafos." << endl;
    outputFile << "\t\tAluno: Rafael de Souza Terra - 201465581C" << endl;
    cout << "----------------------------------"<< endl;
    cout << "Criando grafo a partir do arquivo. "<< endl;
    grafo = gerarGrafo();
    tamanho = grafo->ordemGrafo();
    cout << "Digite o valor da semente para esta execucao: " << endl;
    cin >> seed;
    while(seed < 0)
    {
        cout << "Semente invalida! Digite outro valor." << endl;
        cin >> seed;
    }
    srand(seed);
    cout << "Grafo criado com sucesso!" << endl;
    cout << "----------------------------------"<< endl;
    while(true)
    {
        menu();
        cin >> opcaoEscolhida;
        switch (opcaoEscolhida)
        {
        case 0:
            cout << "O grafo sempre sera exibido da forma: V1 V2 P, onde V1 e V2 correspondem a uma adjacencia com peso P, V1 representa o vertice inicial e V2 o vertice final da adjacencia." << endl;
            cout << "Ao final de cada funcao sera possivel salvar o resultado no arquivo de saida." << endl;
            cout << "Digite 'c' para continuar." << endl;
            while(help != 'c')
                cin >> help;
            limparTela();
            break;
        case 1:
            cout << "Exibindo grafo." <<endl;
            cout << grafo->exibirGrafo();
            if(desejaSalvar())
            {
                outputFile << "Exibindo grafo." << endl;
                outputFile << grafo->exibirGrafo() << endl;

            }
            limparTela();
            break;
        case 2:
            cout << "Digite o vertice desejado." << endl;
            cin >> id;
            while(id < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> id;
            }
            cout << "O grau do vertice " << id << " eh: " << grafo->grauNo(id) << endl;
            if(desejaSalvar())
            {
                outputFile << "\n";
                outputFile << "O grau do vertice " << id << " eh: " << grafo->grauNo(id) << endl;
            }
            limparTela();
            break;
        case 3:
            cout << "O grau do grafo eh: " << grafo->grauGrafo() << endl;
            if(desejaSalvar())
            {
                outputFile << "\n";
                outputFile << "O grau do grafo eh: " << grafo->grauGrafo() << endl;
            }
            limparTela();
            break;
        case 4:
            cout << "Digite o vertice desejado." << endl;
            cin >> id;
            while(id < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> id;
            }
            cout << grafo->listarAdjacentesNo(id) << endl;
            if(desejaSalvar())
            {
                outputFile << "\n";
                outputFile << grafo->listarAdjacentesNo(id) << endl;
            }
            limparTela();
            break;
        case 5:
            if(grafo->verificarKRegular()== -1)
            {
                cout << "O grafo nao eh K-regular." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo nao eh K-regular." << endl;
                }
            }
            else
            {
                cout << "O grafo eh "<<grafo->verificarKRegular() <<"-regular." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo eh "<<grafo->verificarKRegular() <<"-regular." << endl;
                }
            }
            limparTela();
            break;
        case 6:
            if(grafo->verificarGrafoCompleto())
            {
                cout << "O grafo eh completo." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo eh completo." << endl;
                }
            }
            else
            {
                cout << "O grafo nao eh completo." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo nao eh completo." << endl;
                }
            }
            limparTela();
            break;
        case 7:
            if(grafo->verificarGrafoConexo())
            {
                cout << "O grafo eh conexo." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo eh conexo." << endl;
                }
            }
            else
            {
                cout << "O grafo nao eh conexo." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo nao eh conexo." << endl;
                }
            }
            limparTela();
            break;
        case 8:
            if(grafo->verificarGrafoBipartido())
            {
                cout << "O grafo eh bipartido." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo eh bipartido." << endl;
                }
            }
            else
            {
                cout << "O grafo nao eh bipartido." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "O grafo nao eh bipartido." << endl;
                }
            }
            limparTela();
            break;
        case 9:
            cout << "Digite o tamanho do conjunto de vertices." << endl;
            cin >> tam;
            while(tam < 0)
            {
                cout << "Tamanho invalido! Digite novamente." << endl;
                cin >> tam;
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
            gInduzido = grafo->grafoInduzido(tam, vet);
            cout << "Grafo induzido: " << endl;
            cout << gInduzido->exibirGrafo() << endl;
            if(desejaSalvar())
            {
                outputFile << "\n";
                outputFile << "Vertices escolhidos: [";
                for(int i = 0; i<tam; i++)
                {
                    if(i!=tam-1)
                        outputFile << vet[i] << ", ";
                    else
                        outputFile << vet[i];
                }
                outputFile << "]" << endl;
                outputFile << "Grafo induzido: " << endl;
                outputFile << gInduzido->exibirGrafo() << endl;
            }
            delete gInduzido;
            limparTela();
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
            {
                cout << "O vertice "<< id <<" eh de articulacao." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile <<  "O vertice "<< id <<" eh de articulacao." << endl;
                }
            }
            else
            {
                cout << "O vertice "<< id <<" nao eh de articulacao." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile <<  "O vertice "<< id <<" nao eh de articulacao." << endl;
                }
            }
            limparTela();
            break;
        case 11:
            cout << "Grafo complementar: " << endl;
            gComp = grafo->grafoComplementar();
            cout << gComp->exibirGrafo();
            if(desejaSalvar())
            {
                outputFile << "\n";
                outputFile << "Grafo complementar: " << endl;
                outputFile << gComp->exibirGrafo() << endl;
            }
            delete gComp;
            limparTela();
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
            {
                cout << "A aresta (" << ini << "," << fim << ") eh ponte." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile << "A aresta (" << ini << "," << fim << ") eh ponte." << endl;
                }
            }
            else
            {
                cout << "A aresta (" << ini << "," << fim << ") nao eh ponte." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile <<  "A aresta (" << ini << "," << fim << ") nao eh ponte." << endl;
                }
            }
            limparTela();
            break;
        case 13:
            cout << "Digite o vertice de inicio." << endl;
            ini =0;
            cin >> ini;
            while(ini < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> ini;
            }
            cout << "Digite o vertice de destino." << endl;
            fim =0;
            cin >> fim;
            while(fim < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> fim;
            }
            if(grafo->verificarAdjacencia(ini, fim))
            {

                cout << "Os vertices (" << ini << "," << fim << ") sao adjacentes." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile <<  "Os vertices (" << ini << "," << fim << ") sao adjacentes." << endl;
                }
            }
            else
            {

                cout << "Os vertices (" << ini << "," << fim << ") nao sao adjacentes." << endl;
                if(desejaSalvar())
                {
                    outputFile << "\n";
                    outputFile <<   "Os vertices (" << ini << "," << fim << ") nao sao adjacentes." << endl;
                }
            }
            limparTela();
            break;
        case 14:
            cout << "Digite o vertice de inicio." << endl;
            ini =0;
            cin >> ini;
            while(ini < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> ini;
            }
            cout << "Digite o vertice de destino." << endl;
            fim =0;
            cin >> fim;
            while(fim < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> fim;
            }
            cout << "Digite o peso da aresta" << endl;
            cin >> peso;
            if(grafo->existeIdNo(ini) && grafo->existeIdNo(fim) )
            {
                grafo->adicionarAresta(ini, fim, peso);
                cout << "Aresta ("<< ini <<", " << fim << ") criada com sucesso." << endl;
                if (desejaSalvar())
                    outputFile << "Aresta ("<< ini <<", " << fim << ") criada com sucesso." << endl;
            }
            else
            {
                cout << "A aresta nao foi criada pois, pelo menos um vertice nao existe! " << endl;
                if (desejaSalvar())
                    outputFile << "A aresta nao foi criada pois, pelo menos um vertice nao existe! " << endl;
            }
            limparTela();
            break;
        case 15:
            cout << "Digite o vertice." << endl;
            id = 0;
            cin >> id;
            while(id < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> id;
            }
            if(grafo->existeIdNo(id))
            {
                cout << "O vertice "<< id <<" ja existe!" << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" ja existe!" << endl;

            }
            else
            {
                grafo->inserirNo(id);
                cout << "O vertice "<< id <<" foi criado com sucesso." << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" foi criado com sucesso." << endl;
            }
            limparTela();
            break;
        case 16:
            cout << "Digite o vertice de inicio." << endl;
            ini =0;
            cin >> ini;
            while(ini < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> ini;
            }
            cout << "Digite o vertice de destino." << endl;
            fim =0;
            cin >> fim;
            while(fim < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> fim;
            }
            if(grafo->existeIdNo(ini) && grafo->existeIdNo(fim))
            {
                grafo->removerAresta(ini, fim);
                cout << "aresta ("<< ini <<", " << fim << ") removida" << endl;
                if (desejaSalvar())
                    outputFile << "aresta ("<< ini <<", " << fim << ") removida" << endl;
            }
            else
            {
                cout << "A aresta nao foi removida pois, pelo menos um vertice nao existe! " << endl;
                if (desejaSalvar())
                    outputFile << "A aresta nao foi removida pois, pelo menos um vertice nao existe! " << endl;
            }
            limparTela();
            break;
        case 17:
            cout << "Digite o vertice." << endl;
            id = 0;
            cin >> id;
            while(id < 0)
            {
                cout << "Vertice invalido! Digite novamente." << endl;
                cin >> id;
            }
            if(grafo->existeIdNo(id))
            {
                grafo->removerNo(id);
                cout << "O vertice "<< id <<" foi removido com sucesso." << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" foi removido com sucesso." << endl;

            }
            else
            {

                cout << "O vertice "<< id <<" nao existe!" << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" nao existe!" << endl;
            }
            limparTela();
            break;
        case 18:
            cout << "Digite o vertice desejado" << endl;
            id = 0;
            cin >> id;
            if(grafo->existeIdNo(id))
            {
                cout << grafo->fechoTransitivoDireto(id)<< endl;
                if (desejaSalvar())
                    outputFile << grafo->fechoTransitivoDireto(id) << endl;

            }
            else
            {

                cout << "O vertice "<< id <<" nao existe!" << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" nao existe!" << endl;
            }
            limparTela();
            break;
        case 19:
            cout << "Digite o vertice desejado" << endl;
            id = 0;
            cin >> id;
            if(grafo->existeIdNo(id))
            {
                cout << grafo->fechoTransitivoIndireto(id)<< endl;
                if (desejaSalvar())
                    outputFile << grafo->fechoTransitivoIndireto(id) << endl;

            }
            else
            {

                cout << "O vertice "<< id <<" nao existe!" << endl;
                if (desejaSalvar())
                    outputFile << "O vertice "<< id <<" nao existe!" << endl;
            }
            limparTela();
            break;
        case 20:
            cout << "Exibindo grafo transposto." <<endl;
            gTransp = grafo->grafoTransposto();
            cout << gTransp->exibirGrafo() << endl;
            if(desejaSalvar())
            {
                outputFile << "Exibindo grafo transposto." << endl;
                outputFile << gTransp->exibirGrafo()<< endl;

            }
            limparTela();
            break;
        case 21:

            conjSolucaoGuloso = grafo->algoritmoGuloso();
            if(conjSolucaoGuloso!=NULL)
            {
                cout << "Exibindo o resultado do algoritmo." <<endl;
                cout << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
            }
            else
                return -2;
            if(desejaSalvar())
            {
                outputFile << "Algoritmo construtivo guloso." << endl;
                outputFile << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
            }
            delete conjSolucaoGuloso;
            limparTela();
            break;
        case 22:
            cout << "Digite o valor do alfa: "<< endl;
            cin >> alfa;
            while(alfa < 0 || alfa > 1)
            {
                cout << "Alfa invalido! Digite outro valor." << endl;
                cin >> alfa;
            }
            conjSolucaoGuloso = grafo->algGulosoAleatoriedadeParam(alfa);
            conjSolucaoGuloso->setSemente(seed);
            if(conjSolucaoGuloso!=NULL)
            {
                cout << "Algoritmo construtivo guloso com aleatoriedade passada como parametro." <<endl;
                cout << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
                cout << "Semente usada: " << conjSolucaoGuloso->getSemente() << endl;
            }
            else
                return -2;
            if(desejaSalvar())
            {
                outputFile << "Algoritmo construtivo guloso com aleatoriedade passada como parametro." << endl;
                outputFile << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
                outputFile << "Semente usada: " << conjSolucaoGuloso->getSemente() << endl;
                outputFile << "Alfa usado: " << conjSolucaoGuloso->getAlfa() << endl;
            }
            delete conjSolucaoGuloso;
            limparTela();
            break;
        case 23:
            cout << "Digite o tamanho do conjunto de alfas." << endl;
            cin >> tam;
            while(tam < 0)
            {
                cout << "Tamanho invalido! Digite novamente." << endl;
                cin >> tam;
            }
            for(int i = 0; i<tam; i++)
            {
                cout << "Digite o alfa." << endl;
                cin >> vetorAlfas[i];
                while(vetorAlfas[i] < 0)
                {
                    cout << "Alfa invalido! Digite novamente." << endl;
                    cin >> vetorAlfas[i];
                }
            }
            conjSolucaoGuloso = grafo->algGulosoAleatoriedadeAuto(tam, vetorAlfas);
            if(conjSolucaoGuloso!=NULL)
            {
                cout << "Algoritmo construtivo guloso com aleatoriedade ajustada automaticamente.." <<endl;
                cout << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
                cout << "Semente usada: " << conjSolucaoGuloso->getSemente() << endl;
                cout << "Alfas usados: " << endl;
                for(int i = 0; i<tam; i++)
                    cout << vetorAlfas[i] << endl;
                cout << "Melhor Alfa: " << conjSolucaoGuloso->getAlfa() << endl;
            }
            else
                return -2;
            if(desejaSalvar())
            {
                outputFile << "Algoritmo construtivo guloso com aleatoriedade ajustada automaticamente.." <<endl;
                outputFile << "Tamanho do MIS: " << conjSolucaoGuloso->getTamanho() << endl;
                outputFile << "Semente usada: " << conjSolucaoGuloso->getSemente() << endl;
                outputFile << "Alfas usados: " << endl;
                for(int i = 0; i<tam; i++)
                    outputFile << vetorAlfas[i] << endl;
                outputFile << "Melhor Alfa: " << conjSolucaoGuloso->getAlfa() << endl;
            }
            delete conjSolucaoGuloso;
            limparTela();
            break;
        case 24:
            outputFile.close();
            inputFile.close();
            delete grafo;
            cout << "Grafo apagado!" << endl;
            exit(0);
            break;
        default:
            cout << "Opcao invalida! Digite novamente." << endl;
            cin >> opcaoEscolhida;
        }
    }
}

/*Codigos dos erros
    -1 = erro na abertura dos arquivos
    -2 = erro na solucao do algoritmo construtivo guloso
*/
