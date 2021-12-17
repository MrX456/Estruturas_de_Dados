#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

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

        void removeMark();
        void widthSearch(ItemType origin, ItemType destination);
        void depthSearch(ItemType origin, ItemType destination);

    private:
        int nullEdge;
        int maxVertices;
        int numVertices;
        ItemType* vertices;
        int** adjMatrix;
        bool* marks;
};

#endif // GRAPH_H
