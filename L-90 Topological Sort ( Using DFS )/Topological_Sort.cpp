#include <bits/stdc++.h>

using namespace std;

void topoSort(int node, unordered_map<int, list<int>> &adjList, vector<bool> &visited, stack<int> &stackk)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, adjList, visited, stackk);
        }
    }

    // imp
    stackk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    //    prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // call dfs topological sort util function for all component
    vector<bool> visited(v, 0);
    stack<int> stackk;
    for (int node = 0; node < v; node++)
    {
        if (!visited[node])
        {
            topoSort(node, adjList, visited, stackk);
        }
    }

    vector<int> ans;

    while (!stackk.empty())
    {
        ans.push_back(stackk.top());
        stackk.pop();
    }

    return ans;
}
int main()
{

    return 0;
}