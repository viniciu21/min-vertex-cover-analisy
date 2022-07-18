
#include <bits/stdc++.h>
#include <fstream>
#define maxn 100
using namespace std;

// #define resetarGrafo  memset(grafo, 0, sizeof grafo);

class Graph {
    public:
        Graph() {
            this->resetarGrafo();
        }

        bool grafo[maxn][maxn];

        void adicionarAresta(int verticeInicio, int verticeFim){
            
                this->grafo[verticeInicio][verticeFim] = 1;
                this->grafo[verticeFim][verticeInicio] = 1;
        }

        void resetarGrafo() {
            memset(grafo, 0, sizeof grafo);
        }  
};

int recalcularinicio(int inicio)
{
    int c = inicio & -inicio;
    int r = inicio + c;
    return (((r ^ inicio) / 4) / c) | r;
}

bool coberto(int arestas, int meio, int vertices,  bool grafo[100][100])
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

        if (contadorDeVertices == vertices) {
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

// void insertEdge(int u, int v, bool grafo[100][100])
// {
//     grafo[u][v] = 1;
//     grafo[v][u] = 1; // Undirected graph
// }

// Driver code
int main(int argc, char** argv )
{
    if(argv[1] == nullptr) {
        cout << "Coloque o nome do arquivo a ser gerado!" << endl;
        exit(1);
    }
    
    string filename = argv[1];
    filename.append(".txt");
    ofstream MyFile(filename);
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();
    

    // bool grafo[maxn][maxn];

    // teste 1
    // resetarGrafo;

    Graph *gph = new Graph();

    int arestas = 6, vertices = 6;
    gph->adicionarAresta(1, 2);
    gph->adicionarAresta(2, 3);
    gph->adicionarAresta(3, 4);
    gph->adicionarAresta(4, 5);
    gph->adicionarAresta(5, 6);
    gph->adicionarAresta(6, 1);

    cout << "Retorno para o algoritmo de cobertura minima de grafos "
         << NumCoberturaMinima(arestas, vertices, gph->grafo) << endl;

    // teste2
    // memset(grafo, 0, sizeof grafo);

    // V = 6, E = 7;
    // insertEdge(1, 2);
    // insertEdge(1, 3);
    // insertEdge(2, 3);
    // insertEdge(2, 4);
    // insertEdge(3, 5);
    // insertEdge(4, 5);
    // insertEdge(4, 6);
    // cout << "Minimum size of a vertex cover = "
    //      << findMinCover(V, E) << endl;

    return 0;
}
