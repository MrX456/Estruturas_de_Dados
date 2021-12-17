#include "Graph.h"
#include <iostream>
#include <string>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

Graph::Graph(int max, int nullEdgeValues)
{
    numVertices = 0;
    maxVertices = max;
    nullEdge = nullEdgeValues;

    marks = new bool[maxVertices];

    vertices = new ItemType[maxVertices];

    adjMatrix = new int*[maxVertices];
    for(int i = 0; i < maxVertices; i++)
        adjMatrix[i] = new int[maxVertices];

    for(int i = 0; i < maxVertices; i++)
        for(int j = 0; j < maxVertices; j++)
            adjMatrix[i][j] = nullEdge;
}

Graph::~Graph()
{
    delete [] vertices;

    for(int i = 0; i < maxVertices; i++)
        delete [] adjMatrix[i];

    delete [] adjMatrix;
}

int Graph::getIndex(ItemType item)
{
    int index = 0;

    while(item != vertices[index])
        index++;

    return index;
}

bool Graph::isFull()
{
    return (numVertices == maxVertices);
}

void Graph::insertVertex(ItemType item)
{
    if(isFull())
        cout << "Max number of vertexes reached!" << endl;
    else
    {
        vertices[numVertices] = item;
        numVertices++;
    }
}

void Graph::insertEdge(ItemType nodeOut, ItemType nodeIn, int weight)
{
    int row = getIndex(nodeOut);
    int col = getIndex(nodeIn);

    adjMatrix[row][col] = weight;
}

int Graph::getWeight(ItemType nodeOut, ItemType nodeIn)
{
    int row = getIndex(nodeOut);
    int col = getIndex(nodeIn);
    return (adjMatrix[row][col]);
}

int Graph::getDegree(ItemType item)
{
    int row = getIndex(item);
    int degree = 0;

    for(int i = 0 ; i < maxVertices; i++)
        if(adjMatrix[row][i] != nullEdge)
            degree++;

    return degree;
}

void Graph::printMatrix()
{
    cout << "Matriz de adjacencias" << endl;
    for(int i = 0; i < maxVertices; i++)
    {
        for(int j = 0; j < maxVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

void Graph::printVertexes()
{
    cout << "Lista de vertices" << endl;

    for(int i = 0; i < numVertices; i++)
        cout << i << ": " << vertices[i] << endl;
}

void Graph::removeMark()
{
    for(int i = 0 ; i < maxVertices; i++)
        marks[i] = false;
}

//Busca em largura
void Graph::widthSearch(ItemType origin, ItemType destination)
{
    Queue queuedVertexes;
    bool found = false;
    removeMark();

    queuedVertexes.enqueue(origin);

    do
    {
        ItemType actualVertex = queuedVertexes.dequeue();
        if(actualVertex == destination)
        {
            cout << "Visitando: " << actualVertex << endl;
            cout << "Caminho encontrado!" << endl;
            found = true;
        }
        else
        {
            int index = getIndex(actualVertex);
            cout << "Visitando: " << actualVertex << endl;
            for(int i = 0; i < maxVertices; i++)
            {
                if(adjMatrix[index][i] != nullEdge)
                {
                    if(!marks[i])
                    {
                        cout << "Enfileirando: " << vertices[i] << endl;
                        queuedVertexes.enqueue(vertices[i]);
                        marks[i] = true;
                    }
                }
            }
        }
    }
    while(!queuedVertexes.isEmpty() && !found);//A pilha não esta vazia e vertice não foi encontrado

    if(!found)
        cout << "Caminho nao encontrado!" << endl;
}

//Busca em profundidade
void Graph::depthSearch(ItemType origin, ItemType destination)
{
    Stack stackedVertexes;
    bool found = false;
    removeMark();

    stackedVertexes.push(origin);

    do
    {
        ItemType actualVertex = stackedVertexes.pop();
        if(actualVertex == destination)
        {
            cout << "Visitando: " << actualVertex << endl;
            cout << "Caminho encontrado!" << endl;
            found = true;
        }
        else
        {
            int index = getIndex(actualVertex);
            cout << "Visitando: " << actualVertex << endl;
            for(int i = 0; i < maxVertices; i++)
            {
                if(adjMatrix[index][i] != nullEdge)
                {
                    if(!marks[i])
                    {
                        cout << "Empilhando: " << vertices[i] << endl;
                        stackedVertexes.push(vertices[i]);
                        marks[i] = true;
                    }
                }
            }
        }
    }
    while(!stackedVertexes.isEmpty() && !found);//A pilha não esta vazia e vertice não foi encontrado

    if(!found)
        cout << "Caminho nao encontrado!" << endl;
}

//Implemetação do page rank(computar o page rank de todos os vertices)
void Graph::getPageRanks(float* pageRanks)
{
    int* outputDegree = new int[numVertices];

    for(int i = 0; i < numVertices; i++)
    {
        outputDegree[i] = 0;
        for(int j = 0; j < numVertices; j++)
        {
            if(adjMatrix[i][j] != nullEdge)
            {
                outputDegree[i] += 1;
            }
        }
    }

    //Computando page ranks
    float* pr_previous = new float[numVertices]; //rank iteração anterior
    float* pr = new float[numVertices]; //rank iteração atual

    for(int i = 0; i < numVertices; i++)
    {
        pr_previous[i] = 1.0 / numVertices; //Inicializando vertices com page rank 1/n
    }

    float dumpingFactor = .85; // Fator de amortecimento
    for(int numIter = 0; numIter < 100; numIter++)
    {
        for(int i = 0; i < numVertices; i++)
        {
            pr[i] = 0;
            for(int j = 0; j < numVertices; j++)
            {
                if(adjMatrix[j][i] != nullEdge)
                {
                    pr[i] += pr_previous[j] / outputDegree[j];
                }
            }
            pr[i] = (1 - dumpingFactor) / numVertices + dumpingFactor * pr[i];
        }
        for(int i = 0; i < numVertices; i++)
        {
            pr_previous[i] = pr[i];
        }
    }

    //Retornar valores e desalocar a memória
    for(int i = 0; i < numVertices; i++)
    {
        pageRanks[i] = pr[i];
    }
    delete [] pr_previous;
    delete [] pr;
    delete [] outputDegree;
}
