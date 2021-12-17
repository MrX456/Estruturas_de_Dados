#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

Graph::Graph(int max, int nullEdgeValues)
{
    numVertices = 0;
    maxVertices = max;
    nullEdge = nullEdgeValues;

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

    //Remover se for direcionado
    adjMatrix[col][row] = weight;
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
