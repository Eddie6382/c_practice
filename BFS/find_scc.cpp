#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g4(9);
    g4.AddEdgeList(0, 1);
    g4.AddEdgeList(1, 2);
    g4.AddEdgeList(1, 4);
    g4.AddEdgeList(2, 0);
    g4.AddEdgeList(2, 3);
    g4.AddEdgeList(2, 5);
    g4.AddEdgeList(3, 2);
    g4.AddEdgeList(4, 5);
    g4.AddEdgeList(4, 6);
    g4.AddEdgeList(5, 4);
    g4.AddEdgeList(5, 6);
    g4.AddEdgeList(5, 7);
    g4.AddEdgeList(6, 7);
    g4.AddEdgeList(7, 8);
    g4.AddEdgeList(8, 6);

    cout << "Vertex(0) as starting point for the First DFS():\n\n";
    g4.PrintSCCs();
    cout << "Vertex(3) as starting point for the First DFS():\n\n";
    g4.PrintSCCs(3);
}