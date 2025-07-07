#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int &timer,
         vector<int> &disc, vector<int> &low, vector<vector<int>> &result,
         unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;

        if (!visited[neighbour])
        {
            dfs(neighbour, node, timer, disc, low, result, visited, adjList);
            low[node] = min(low[node], low[neighbour]);

            // check bridge
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);

                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    //    adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> visited;

    // dfs
    vector<vector<int>> result;
    for (int node = 0; node < v; node++)
    {
        if (!visited[node])
        {
            dfs(node, parent, timer, disc, low, result, visited, adjList);
        }
    }

    return result;
}
int main()
{

    return 0;
}