#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    int noOfVertex;
    int noOfEdges;

    void addAdj(int v, int u, bool isDirected)
    {
        // 0 -> Undirected
        // 1 -> Directed

        adjList[v].push_back(u);

        if (!isDirected)
        {
            adjList[u].push_back(v);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // Undirected + Disconnected Graph
    void bfsTraversalForUndirectedGraph()
    {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(0);

        for (int node = 0; node < noOfVertex; node++)
        {
            if (!visited[node])
            {
                bfs(visited, node);
            }
        }
    }

    void bfs(unordered_map<int, bool> visited, int node)
    {
        queue<int> q;
        q.push(node);

        visited[node] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            cout << frontNode << " ";

            // For Disconnected Graph
            for (auto i : adjList[frontNode])
            {
                if (!visited[node])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // Directed + Disconnected Graph
    void bfsTraversalForDirectedGraph()
    {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(0);

        for (int node = 0; node < noOfVertex; node++)
        {
            if (!visited[node])
            {
                bfs(visited, node);
            }
        }
    }

    void bfsTraversalForDirectedGraph(int n, vector<vector<int>> &adj)
    {

        queue<int> q;

        // Start BFS from vertex 0
        q.push(0);

        // Initialize the visited array with all zeros
        vector<int> visited(n, 0);

        visited[0] = 1;

        while (!q.empty())
        {
            // Get Front Of Queue
            int frontNode = q.front();
            q.pop();

            cout << frontNode << ", ";

            for (auto i : adj[frontNode])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    /*
    Graph *g = new Graph();
    cout << "Enter No Of Vertex : ";
    cin >> g->noOfVertex;

    int noOfEdge;
    cout << "Enter No Of Edge : ";
    cin >> g->noOfEdges;

    for (int i = 0; i < g->noOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected graph
        g->addAdj(u, v, 0);
    }

    g->printAdjList();

    g->bfsTraversalForUndirectedGraph();
    */

    Graph *directedGraph = new Graph();
    cout << "Enter No Of Vertex : ";
    cin >> directedGraph->noOfVertex;

    cout << "Enter No Of Edge : ";
    cin >> directedGraph->noOfEdges;

    for (int i = 0; i < directedGraph->noOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected graph
        directedGraph->addAdj(u, v, 1);
    }

    directedGraph->printAdjList();

    directedGraph->bfsTraversalForDirectedGraph();

    /**
#1
5 6
0 1
0 2
1 2
1 3
2 4
3 4
#2
5 5
1 2
1 0
2 0
2 3
2 4

#3
6 5
0 1
0 2
0 3
1 4
2 5

#4
8 7
0 1
0 2
0 3
1 4
1 7
2 5
3 6

     */
    return 0;
}