#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g3(9);
    //construct a graph
    g3.AddEdgeList(0, 1);
    g3.AddEdgeList(1, 0);
    g3.AddEdgeList(1, 4);
    g3.AddEdgeList(1, 5);
    g3.AddEdgeList(3, 6);
    g3.AddEdgeList(4, 1);
    g3.AddEdgeList(4, 5);
    g3.AddEdgeList(5, 1);
    g3.AddEdgeList(5, 4);
    g3.AddEdgeList(5, 7);
    g3.AddEdgeList(6, 3);
    g3.AddEdgeList(6, 8);
    g3.AddEdgeList(7, 5);
    g3.AddEdgeList(8, 6);

    g3.CCDFS();
    cout << endl;
    g3.CCBFS();
    cout << endl;
    return 0;
}
