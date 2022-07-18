
#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#define maxn 100
using namespace std;

// #define resetarGrafo  memset(grafo, 0, sizeof grafo);

class Graph
{
public:
    Graph()
    {
        this->resetarGrafo();
    }

    bool grafo[maxn][maxn];

    void ajustarArray(bool arr[maxn][maxn])
    {
        for (size_t i = 0; i < maxn; i++)
        {
            for (size_t j = 0; j < maxn; j++)
            {
                this->grafo[i][j] = arr[i][j];
            }
        }
    }

    void printMatrix()
    {
        for (size_t i = 0; i < maxn; i++)
        {
            for (size_t j = 0; j < maxn; j++)
            {
                cout << this->grafo[i][j];
            }
            cout << endl;
        }
    }

    void adicionarAresta(int verticeInicio, int verticeFim)
    {
        this->grafo[verticeInicio][verticeFim] = 1;
        this->grafo[verticeFim][verticeInicio] = 1;
    }

    void resetarGrafo()
    {
        memset(grafo, 0, sizeof grafo);
    }
};

int recalcularinicio(int inicio)
{
    int c = inicio & -inicio;
    int r = inicio + c;
    return (((r ^ inicio) / 4) / c) | r;
}

bool coberto(int arestas, int meio, int vertices, bool grafo[100][100])
{
    bool result = false;
    int inicio = (1 * pow(2, meio)) - 1;
    int fim = (1 * pow(2, arestas));
    bool grafoDePara[maxn][maxn];

    while (inicio < fim)
    {
        memset(grafoDePara, 0, sizeof grafoDePara);
        int contadorDeVertices = 0;

        for (int j = 1, v = 1; j < fim; j = j * 2, v++)
        {
            if (inicio & j)
            {
                for (int k = 1; k <= arestas; k++)
                {
                    if (grafo[v][k] && !grafoDePara[v][k])
                    {
                        grafoDePara[v][k] = 1;
                        grafoDePara[k][v] = 1;
                        contadorDeVertices++;
                    }
                }
            }
        }

        if (contadorDeVertices == vertices)
        {
            result = true;
            return result;
        }

        inicio = recalcularinicio(inicio);
    }
    result = false;
    return result;
}

int NumCoberturaMinima(int arestas, int vertices, bool grafo[100][100])
{
    int inicio = 1, fim = arestas;
    while (fim > inicio)
    {
        int meio = (inicio + fim) / 2;
        if (coberto(arestas, meio, vertices, grafo) == false)
            inicio = meio + 1;
        else
            fim = meio;
    }

    return inicio;
}

int main(int argc, char **argv)
{
    if (argv[1] == nullptr)
    {
        cout << "Coloque o nome do arquivo a ser gerado!" << endl;
        exit(1);
    }

    int choice;

    string filename = argv[1];
    filename.append(".txt");
    ofstream GraphFile;
    ifstream isFileExists;
    isFileExists.open(filename);
    if (!isFileExists)
    {
        GraphFile.open(filename);
        GraphFile
            << left
            << setw(20)
            << "| Solucao Algoritmo "
            << left
            << setw(20)
            << "| Tempo Algoritmo (microseconds) "
            << left
            << setw(20)
            << "| Num.Vértices "
            << left
            << setw(20)
            << "| Num. Arestas |"
            << left
            << setw(20)
            << " Melhor Solução |"
            << endl;
        GraphFile.close();
    }

    cout << "Escolha uma das instâncias" << endl;

    cout << "1: 6 arestas e 6 vertices" << endl;

    cout << "2: 16 arestas e 8 vertices" << endl;

    cout << "3: 6 arestas e 7 vertices" << endl;

    cout << "4: 13 arestas e 10 vertices" << endl;

    cout << "5: 15 arestas e 14 vertices" << endl;

    cout << "6: 6 arestas e 6 vertices" << endl;

    cout << "7: 6 arestas e 6 vertices" << endl;

    cout << "8: 6 arestas e 6 vertices" << endl;

    cout << "9: 6 arestas e 6 vertices" << endl;

    cout << "10: 6 arestas e 6 vertices" << endl;

    cin >> choice;
    // bool array[100][100];
    // memset(array, 0, sizeof array);
    while (choice >= 10)
    {
        cout << "Por favor, escolha uma opção entre 1 e 10" << endl;
        cin >> choice;
    }
    int arestas, vertices;

    Graph *gph = new Graph();

    switch (choice)
    {
    case 1:
    {
        arestas = 6;
        vertices = 6;
        gph->adicionarAresta(1, 2);
        gph->adicionarAresta(2, 3);
        gph->adicionarAresta(3, 4);
        gph->adicionarAresta(4, 5);
        gph->adicionarAresta(5, 6);
        gph->adicionarAresta(6, 1);
        break;
    }
    case 2:
    {
        arestas = 16;
        vertices = 8;
        gph->adicionarAresta(1, 2);
        gph->adicionarAresta(1, 5);
        gph->adicionarAresta(1, 6);
        gph->adicionarAresta(1, 8); // A
        gph->adicionarAresta(5, 6);
        gph->adicionarAresta(2, 5);
        gph->adicionarAresta(2, 3);
        gph->adicionarAresta(2, 7);
        gph->adicionarAresta(2, 4); // B
        gph->adicionarAresta(3, 6);
        gph->adicionarAresta(3, 8);
        gph->adicionarAresta(3, 4);
        gph->adicionarAresta(6, 5);
        gph->adicionarAresta(5, 7);
        gph->adicionarAresta(7, 8);
        gph->adicionarAresta(8, 4);

        break;
    }
    case 3:
    {
        arestas = 6;
        vertices = 7;
        gph->adicionarAresta(1, 2);
        gph->adicionarAresta(1, 3);
        gph->adicionarAresta(2, 4);
        gph->adicionarAresta(2, 5);
        gph->adicionarAresta(3, 6);
        gph->adicionarAresta(3, 7);
    }
    case 4:
    {
        arestas = 13;
        vertices = 10;
        gph->adicionarAresta(1, 3);
        gph->adicionarAresta(1, 9);
        gph->adicionarAresta(3, 9);
        gph->adicionarAresta(9, 2);
        gph->adicionarAresta(9, 4);
        gph->adicionarAresta(2, 4);
        gph->adicionarAresta(4, 7);
        gph->adicionarAresta(4, 8);
        gph->adicionarAresta(7, 8);
        gph->adicionarAresta(4, 6);
        gph->adicionarAresta(6, 5);
        gph->adicionarAresta(6, 10);
        gph->adicionarAresta(5, 10);
    }
    case 5: {
        arestas = 15;
        vertices = 14;
        
        gph->adicionarAresta(1, 5);
        gph->adicionarAresta(1, 4);
        gph->adicionarAresta(1, 8);
        gph->adicionarAresta(8, 2);
        gph->adicionarAresta(2, 12);
        gph->adicionarAresta(9, 3);
        gph->adicionarAresta(9, 14);
        gph->adicionarAresta(9, 13);
        gph->adicionarAresta(9, 10);
        gph->adicionarAresta(7, 8);
        gph->adicionarAresta(14, 3);
        gph->adicionarAresta(13, 10);
        gph->adicionarAresta(12, 3);
        gph->adicionarAresta(12, 6);
        gph->adicionarAresta(10, 11);

    }
    }
    auto inicioExe = std::chrono::high_resolution_clock::now();
    int numCoberturaMinimaResult = NumCoberturaMinima(arestas, vertices, gph->grafo);
    auto resultado = std::chrono::high_resolution_clock::now() - inicioExe; 
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
    
    cout
            << left
            << setw(20)
            << "|"
            << to_string(numCoberturaMinimaResult)
            << left
            << setw(20)
            << "| "
            << to_string(microseconds)
            << left
            << setw(20)
            << "| "
            << to_string(vertices)
            << left
            << setw(20)
            << "|" + to_string(arestas) + "|"
            << left
            << setw(20)
            << " Melhor Solução |"
            << endl;

     GraphFile.open(filename, ios_base::openmode::_S_app);
     GraphFile
            << right
            << setw(10)
            << "|"
            << to_string(numCoberturaMinimaResult)
            << right
            << setw(20)
            << "| "
            << to_string(microseconds)
            << right
            << setw(20)
            << "| "
            << to_string(vertices)
            << right
            << setw(20)
            << "|" + to_string(arestas) + "|"
            << right
            << setw(10)
            << " Melhor Solução |"
            << endl;

    GraphFile.close();

    return 0;
}