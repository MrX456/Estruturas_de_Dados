#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <iostream>

using namespace std;

typedef string ItemType;

class Graph
{
    public:
        Graph(int max, int nullEdgeValues);
        ~Graph();
        int getIndex(ItemType item);
        bool isFull();
        void insertVertex(ItemType item);
        void insertEdge(ItemType nodeOut, ItemType nodeIn, int weight);
        int getWeight(ItemType nodeOut, ItemType nodeIn);
        int getDegree(ItemType item);
        void printMatrix();
        void printVertexes();

    private:
        int nullEdge;
        int maxVertices;
        int numVertices;
        ItemType* vertices;
        int** adjMatrix;
};

#endif // GRAPH_H
