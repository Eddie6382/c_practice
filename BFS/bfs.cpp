#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    int num_vertex;
    vector<list<int>> Adjlist; //use adjacency list to represent the gragh
    int *color,                // 0:white, 1:gray, 2:black
        *distance,             // 0:start, INF:can not approach
        *predecessor;          // -1:no predecessor, represent start
public:
    Graph() : num_vertex(0){};
    Graph(int N) : num_vertex(N)
    {
        Adjlist.resize(num_vertex);
    };
    void AddEdgeList(int from, int to);
    void BFS(int Start);
    void get_shortestpath(int End);
    void get_color()
    {
        cout << "color: ";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << color[i];
        }
        cout << endl;
    }
    void get_distance()
    {
        cout << "distance: ";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << distance[i];
        }
        cout << endl;
    }
    void get_predecessor()
    {
        cout << "predecessor: ";
        for (int i = 0; i < num_vertex; i++)
        {
            cout << predecessor[i];
        }
        cout << endl;
    }
};

void Graph::AddEdgeList(int from, int to)
{
    Adjlist[from].push_back(to);
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
                for (list<int>::iterator itr = Adjlist[u].begin(); itr != Adjlist[u].end(); itr++)
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

int main()
{
    Graph g1(9);
    //construct a graph
    g1.AddEdgeList(0, 1);
    g1.AddEdgeList(0, 2);
    g1.AddEdgeList(0, 3);
    g1.AddEdgeList(1, 0);
    g1.AddEdgeList(1, 4);
    g1.AddEdgeList(2, 0);
    g1.AddEdgeList(2, 4);
    g1.AddEdgeList(2, 5);
    g1.AddEdgeList(2, 6);
    g1.AddEdgeList(2, 7);
    g1.AddEdgeList(3, 0);
    g1.AddEdgeList(3, 7);
    g1.AddEdgeList(4, 1);
    g1.AddEdgeList(4, 2);
    g1.AddEdgeList(4, 5);
    g1.AddEdgeList(5, 2);
    g1.AddEdgeList(5, 4);
    g1.AddEdgeList(5, 8);
    g1.AddEdgeList(6, 2);
    g1.AddEdgeList(6, 7);
    g1.AddEdgeList(6, 8);
    g1.AddEdgeList(7, 2);
    g1.AddEdgeList(7, 3);
    g1.AddEdgeList(7, 6);
    g1.AddEdgeList(8, 5);
    g1.AddEdgeList(8, 6);

    g1.BFS(0);
    g1.get_color();
    g1.get_distance();
    g1.get_predecessor();
    g1.get_shortestpath(5);
    return 0;
}