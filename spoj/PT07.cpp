// A C++ Program to detect cycle in an undirected graph
#include<iostream>
#include <list>
#include <limits.h>
#include <cstdio>
using namespace std;

// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();   // returns true if there is a cycle
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    int u = 0;
    if (isCyclicUtil(u, visited, -1))
        return true;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            return true;
    }
    return false;
}

// Driver program to test above functions
int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    Graph g1(n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g1.addEdge(--a, --b);
    }
    if (!g1.isCyclic()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }


    return 0;
}
