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

    void dfs(int vertex, vector<int> &visited, vector<int> &singleComponent, unordered_map<int, list<int>> &graph)
    {
        visited[vertex] = 1;
        cout << vertex << ", ";
        singleComponent.push_back(vertex);

        for (auto child : graph[vertex])
        {
            // Check if the node is visited before or not.
            if (!visited[child])
            {
                dfs(child, visited, singleComponent, graph);
            }
        }
    }

    vector<vector<int>> depthFirstSearch()
    {
        // Creating Adjacency Matrix.
        int V = noOfVertex;
        int E = noOfEdges;

        vector<vector<int>> ans;
        vector<int> visited(V, 0);

        for (int vertex = 0; vertex < V; vertex++)
        {
            if (!visited[vertex])
            {
                vector<int> singleComponent;
                dfs(vertex, visited, singleComponent, adjList);
                ans.push_back(singleComponent);
            }
        }
        return ans;
    }
};

int main()
{
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

    g->depthFirstSearch();

    /**
#1
5 4
0 2
0 1
1 2
3 4

#2
9 7
0 1
0 2
0 5
3 6
7 4
4 8
7 8

     */
    return 0;
}