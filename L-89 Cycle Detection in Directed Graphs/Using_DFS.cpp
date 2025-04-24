#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

bool checkCycleDetectedByDFS(int node,
                             unordered_map<int, bool> &visited,
                             unordered_map<int, bool> &dfsVisited,
                             unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool isCycleDetected = checkCycleDetectedByDFS(neighbour, visited, dfsVisited, adjList);

            if (isCycleDetected)
                return true;
        }
        else if (visited[neighbour] && dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int node = 1; node <= n; node++)
    {
        if (!visited[node])
        {
            bool isCycleDetected = checkCycleDetectedByDFS(node, visited, dfsVisited, adjList);

            if (isCycleDetected)
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}