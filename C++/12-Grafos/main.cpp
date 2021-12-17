#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
   int max,
        nullEdgeValues;

    cout << "Digite a quantidade máxima de vertices : ";
    cin >> max;
    cout << "Digite o valor para representar a ausencia de aresta : ";
    cin >> nullEdgeValues;

    Graph graph(max, nullEdgeValues);
    ItemType item1,
             item2;
    int opt,
        value,
        weight;

    do
    {
        cout << "Digite 0 para parar o algoritmo" << endl;
        cout << "Digite 1 para inserir um vertice" << endl;
        cout << "Digite 2 para inserir uma aresta" << endl;
        cout << "Digite 3 para imprimir o grau de um vertice" << endl;
        cout << "Digite 4 para imprimir o peso de uma aresta" << endl;
        cout << "Digite 5 para imprimir a matriz de adjacencias" << endl;
        cout << "Digite 6 para imprimir a lista de vertices" << endl;
        cin >> opt;

        if(opt == 1)
        {
            cout << "Digite o elemento do vertice a ser inserido : " << endl;
            cin >> item1;
            graph.insertVertex(item1);
        }
        else if(opt == 2)
        {
            cout << "Digite o vertice de saida : " << endl;
            cin >> item1;
            cout << "Digite o vertice de entrada : " << endl;
            cin >> item2;
            cout << "Digite o peso da aresta : " << endl;
            cin >> weight;
            graph.insertEdge(item1, item2, weight);
        }
        else if(opt == 3)
        {
            cout << "Digite o vertice que sera calculado o grau : " << endl;
            cin >> item1;
            value = graph.getDegree(item1);
            cout << "O grau desse vertice e " << value << endl;
        }
        else if(opt == 4)
        {
            cout << "Digite o vertice de saida : " << endl;
            cin >> item1;
            cout << "Digite o vertice de entrada : " << endl;
            cin >> item2;;
            value = graph.getWeight(item1, item2);
            cout << "O peso da aresta e " << value << endl;
        }
        else if(opt == 5)
        {
            graph.printMatrix();
        }
        else if(opt == 6)
        {
            graph.printVertexes();
        }
    }
    while(opt != 0);

    return 0;
}
