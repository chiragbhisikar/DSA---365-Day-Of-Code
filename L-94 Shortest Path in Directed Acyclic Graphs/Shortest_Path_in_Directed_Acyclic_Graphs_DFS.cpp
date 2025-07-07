#include <bits/stdc++.h>

using namespace std;

void dfs(int node,
         vector<bool> &visited,
         stack<int> &topologicalSort,
         unordered_map<int, list<pair<int, int>>> &adjList)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first, visited, topologicalSort, adjList);
        }
    }

    topologicalSort.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // preparing adjancecy list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    /*
        // print adjancecy list
        for(auto node : adjList){
            cout << node.first << endl;

            for(auto n : node.second){
                cout << "\t" << n.first << "->" << n.second << endl;
            }
            cout << endl;
        }
    */

    vector<bool> visited(n, false);
    stack<int> topologicalSort;
    // topological Sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, topologicalSort, adjList);
        }
    }

    int src = 0;
    vector<int> distance(n);

    for (int i = 0; i < n; i++)
    {
        if (i != src)
        {
            distance[i] = INT_MAX;
        }
    }

    distance[src] = 0;

    while (!topologicalSort.empty())
    {
        int top = topologicalSort.top();
        topologicalSort.pop();

        if (distance[top] != INT_MAX)
        {
            for (auto node : adjList[top])
            {

                int totalDistance = distance[top] + node.second;
                if (totalDistance < distance[node.first])
                {
                    distance[node.first] = totalDistance;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
        {
            distance[i] = -1;
        }
    }

    return distance;
}

int main()
{

    return 0;
}