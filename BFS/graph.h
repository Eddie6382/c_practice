#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

class Graph
{
private:
    int num_vertex;
    vector<list<int>> AdjList; //use adjacency list to represent the gragh
    int *color,                // 0:white, 1:gray, 2:black
        *distance,             // 0:start, INF:can not approach
        *discover,
        *finish,
        *predecessor; // -1:no predecessor, represent start
public:
    Graph() : num_vertex(0){};
    Graph(int N) : num_vertex(N)
    {
        AdjList.resize(num_vertex);
    };

    int GetColor(int i) { return color[i]; };
    int GetFinish(int i) { return finish[i]; };
    int GetPredecessor(int i) { return predecessor[i]; };

    void AddEdgeList(int from, int to);

    void BFS(int Start);
    void DFS(int start);
    void DFSVisit(int vertex, int &time);
    void VariableInitializeDFS(); //dynamic memory allocation for the data needed by DFS

    void CCDFS(int vertex);
    void CCBFS(int vertex = 0);
    void SetCollapsing(int vertex);
    void get_shortestpath(int End);

    Graph GraphTranspose(); // data type is graph
    void PrintSCCs(int start = 0);

    void PrintColor()
    {
        cout << "color: ";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << color[i];
        }
        cout << endl;
    }
    void PrintDistance()
    {
        cout << "distance: ";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << distance[i];
        }
        cout << endl;
    }
    void PrintDiscover()
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << ' ' << discover[i];
        }
        cout << endl;
    }
    void PrintFinish()
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << i;
        }
        cout << endl;
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << finish[i];
        }
        cout << endl;
    }
    void PrintPredecessor()
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << i;
        }
        cout << endl;
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << predecessor[i];
        }
        cout << endl;
    }
    void PrintDataArray(int *array)
    {
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << i;
        }
        cout << endl;
        for (int i = 0; i < num_vertex; i++)
        {
            cout << setw(4) << array[i];
        }
        cout << endl;
    }

    friend void QuickSort(int *vec, int front, int end, int *vec2);
    friend int Partition(int *vec, int front, int end, int *vec2);
    friend void swap(int *x, int *y);

    void TopologicalSort(int Start = 0);
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int *vec, int front, int end, int *vec2)
{
    // from large to small
    int pivot = vec[end];
    int i = front - 1;
    for (int j = front; j < end; j++)
    {
        if (vec[j] > pivot)
        {
            i++;
            // change the address of two variable, &vec[i] means the address of vec[i]
            swap(&vec[i], &vec[j]);
            swap(&vec2[i], &vec2[j]);
        }
    }
    swap(&vec[i + 1], &vec[end]);
    swap(&vec2[i + 1], &vec2[end]);

    return i + 1; // take i+1 as the breakpoint of the next recursive point
}

void QuickSort(int *vec, int front, int end, int *vec2)
{
    if (front < end)
    {
        int pivot = Partition(vec, front, end, vec2);
        QuickSort(vec, front, pivot - 1, vec2);
        QuickSort(vec, pivot + 1, end, vec2);
    }
}

void Graph::AddEdgeList(int from, int to)
{
    AdjList[from].push_back(to);
}

void Graph::BFS(int Start)
{
    color = new int[num_vertex];
    predecessor = new int[num_vertex];
    distance = new int[num_vertex];
    // initiation
    for (int i = 0; i < num_vertex; i++)
    {
        color[i] = 0;                 //0: not found
        predecessor[i] = -1;          //-1: no predecessor
        distance[i] = num_vertex + 1; //longest distance = num_vertex-1 edges
    }
    queue<int> q;
    int i = Start; //set up the start point

    for (int j = 0; j < num_vertex; j++) //j run through all the vertex
    {
        if (color[i] == 0)
        {
            color[i] = 1;        //1: node has be found
            distance[i] = 0;     //the distance of the start of every connected component is 0
            predecessor[i] = -1; //start point has no predecessor
            q.push(i);
            // below is the hole process finding the shortest path
            while (!q.empty())
            {
                int u = q.front(); //u, new start of searching
                // use iterstor
                for (list<int>::iterator itr = AdjList[u].begin(); itr != AdjList[u].end(); itr++)
                {
                    if (color[*itr] == 0)
                    { //not found
                        color[*itr] = 1;
                        distance[*itr] = distance[u] + 1;
                        predecessor[*itr] = u;
                        q.push(*itr);
                    }
                }
                q.pop(); //delete u(front)
                color[u] = 2;
            }
        }
        /*
        if not every vertex reached in the first loop, it means that there are
        more than one connecyed component
        let i = j to ensure that every vertex be found
         */
        i = j;
    }
}

void Graph::get_shortestpath(int End)
{
    stack<int> s;
    while (predecessor[End] != -1)
    {
        s.push(End);
        End = predecessor[End];
    }
    cout << "shortest path: ";
    while (!s.empty())
    {
        cout << ' ' << s.top();
        s.pop();
    }
}

void Graph::VariableInitializeDFS()
{
    color = new int[num_vertex];
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    predecessor = new int[num_vertex];

    for (int i = 0; i < num_vertex; i++)
    {
        color[i] = 0;
        discover[i] = 0;
        finish[i] = 0;
        predecessor[i] = -1;
    }
}

void Graph::DFS(int start)
{
    VariableInitializeDFS();
    int time = 0; //initialization
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

void Graph::SetCollapsing(int current)
{
    int root;
    for (root = current; predecessor[root] >= 0; root = predecessor[root])
        ;
    while (current != root)
    {
        int parent = predecessor[current];
        predecessor[current] = root;
        current = parent;
    }
}

void Graph::CCDFS(int vertex = 0)
{
    DFS(vertex);
    cout << "before set collapsing, predecessor: " << endl;
    PrintPredecessor();
    // find all collapsed tree
    for (int i = 0; i < num_vertex; i++)
    {
        SetCollapsing(i);
    }
    cout << "after set collapsing, predecessor: " << endl;
    PrintPredecessor();

    // find connected componnent
    int num_cc = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (predecessor[i] < 0)
        {
            cout << "Component# " << ++num_cc << ": " << i << " ";
            for (int j = 0; j < num_vertex; j++)
            {
                if (predecessor[j] == i)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
}

void Graph::CCBFS(int vertex)
{
    BFS(vertex);
    PrintPredecessor();
    // find all collapsed tree
    for (int i = 0; i < num_vertex; i++)
    {
        SetCollapsing(i);
    }
    PrintPredecessor();

    // find connected componnent
    int num_cc = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (predecessor[i] < 0)
        {
            cout << "Component# " << ++num_cc << ": " << i << " ";
            for (int j = 0; j < num_vertex; j++)
            {
                if (predecessor[j] == i)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
}

void Graph::PrintSCCs(int start)
{
    // 1st DFS, to find finish[]
    DFS(start);
    cout << "First DFS on G, finish time: " << endl;
    PrintFinish();

    // generate a transpose of graph
    Graph gT(num_vertex);
    gT = GraphTranspose();

    // use matrix finishLargetoSmall[] to store the order of vertex according finish time
    int finishLargetoSmall[num_vertex];
    for (int i = 0; i < num_vertex; i++)
    {
        finishLargetoSmall[i] = i;
    }

    // Quicksort will refresh the order of finishLargetoSmall[]
    QuickSort(finish, 0, num_vertex - 1, finishLargetoSmall);

    cout << "finish time large to small: " << endl;
    PrintDataArray(finishLargetoSmall);

    // 2nd DFS on gT, initialize
    gT.VariableInitializeDFS();
    int time = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (gT.GetColor(finishLargetoSmall[i]) == 0)
        {
            gT.DFSVisit(finishLargetoSmall[i], time);
        }
    }

    cout << "second DFS() on gT, finish time: \n";
    gT.PrintFinish();
    cout << "predecessor[] before Setcollapsing: \n";
    gT.PrintPredecessor();
    for (int i = 0; i < num_vertex; i++)
    {
        gT.SetCollapsing(i);
    }
    cout << "predecessor[] after Setcollapsing: \n";
    gT.PrintPredecessor();

    // find strongly connected component
    int num_cc = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (gT.GetPredecessor(i) < 0)
        {
            cout << "SCC#" << ++num_cc << ": " << i << " ";
            for (int j = 0; j < num_vertex; j++)
            {
                if (gT.GetPredecessor(j) == i)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

Graph Graph::GraphTranspose()
{
    Graph gT(num_vertex);
    for (int i = 0; i < num_vertex; i++)
    {
        for (list<int>::iterator itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++)
        {
            gT.AddEdgeList(*itr, i);
        }
    }
    return gT;
}

void Graph::TopologicalSort(int Start)
{
    DFS(Start);
    int finishLargetoSmall[num_vertex];
    for (int i = 0; i < num_vertex; i++)
    {
        finishLargetoSmall[i] = i;
    }
    //QuickSort will rrefresh the order of vertex from ;arge to small in finish time
    QuickSort(finish, 0, num_vertex - 1, finishLargetoSmall);

    cout << "Topological Sort: \n";
    for (int i = 0; i < num_vertex; i++)
    {
        cout << setw(3) << finishLargetoSmall[i];
    }
    cout << endl;
}

#endif