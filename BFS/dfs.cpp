#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>

using namespace std;

class Graph
{
private:
    int num_vertex;
    vector<list<int>> AdjList;
    int *color, *predecessor, *discover, *finish;

public:
    Graph() : num_vertex(0){};
    Graph(int N) : num_vertex(N)
    {
        AdjList.resize(num_vertex);
    };
    void AddEdgeList(int from, int to);
    void BFS(int start);
    void DFS(int start);
    void DFSVisit(int vertex, int &time);
    void get_discover()
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << discover[i];
        }
        cout << endl;
    }
    void get_finish()
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << finish[i];
        }
        cout << endl;
    }
    void get_predecessor()
    {
        cout << "predecessor:";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << predecessor[i];
        }
        cout << endl;
    }
};

void Graph::AddEdgeList(int from, int to)
{
    AdjList[from].push_back(to);
}

void Graph::DFS(int start)
{
    color = new int[num_vertex];
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    predecessor = new int[num_vertex];

    int time = 0; //initialization
    for (int i = 0; i < num_vertex; i++)
    {
        color[i] = 0;
        discover[i] = 0;
        finish[i] = 0;
        predecessor[i] = 0;
    }

    int i = start;
    for (int j = 0; j < num_vertex; j++)
    {
        if (color[i] == 0)
        {
            DFSVisit(i, time);
        }
        i = j; //the graph may not be connected, j will run through all the vertexs
    }
}

void Graph::DFSVisit(int vertex, int &time)
{
    color[vertex] = 1;
    discover[vertex] = ++time;
    for (list<int>::iterator itr = AdjList[vertex].begin();
         itr != AdjList[vertex].end(); itr++)
    {
        if (color[*itr] == 0)
        {
            predecessor[*itr] = vertex;
            DFSVisit(*itr, time);
        }
    }
    color[vertex] = 2;
    finish[vertex] = ++time;
}

int main()
{
    Graph g2(8);
    g2.AddEdgeList(0, 1);
    g2.AddEdgeList(0, 2);
    g2.AddEdgeList(1, 3);
    g2.AddEdgeList(2, 1);
    g2.AddEdgeList(2, 5);
    g2.AddEdgeList(3, 4);
    g2.AddEdgeList(3, 5);
    g2.AddEdgeList(5, 1);
    g2.AddEdgeList(6, 4);
    g2.AddEdgeList(6, 7);
    g2.AddEdgeList(7, 6);

    g2.DFS(0);
    g2.get_discover();
    g2.get_finish();
    g2.get_predecessor();
    return 0;
}
