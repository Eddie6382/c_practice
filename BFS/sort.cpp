#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g5(15); // 建立如圖二(a)的DAG
    g5.AddEdgeList(0, 2);
    g5.AddEdgeList(1, 2);
    g5.AddEdgeList(2, 6);
    g5.AddEdgeList(2, 7);
    g5.AddEdgeList(3, 4);
    g5.AddEdgeList(4, 5);
    g5.AddEdgeList(5, 6);
    g5.AddEdgeList(5, 14);
    g5.AddEdgeList(6, 8);
    g5.AddEdgeList(6, 9);
    g5.AddEdgeList(6, 11);
    g5.AddEdgeList(6, 12);
    g5.AddEdgeList(7, 8);
    g5.AddEdgeList(9, 10);
    g5.AddEdgeList(12, 13);

    g5.TopologicalSort();
    g5.TopologicalSort(4);

    return 0;
}