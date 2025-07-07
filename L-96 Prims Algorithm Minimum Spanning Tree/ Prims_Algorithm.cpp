#include <bits/stdc++.h>

using namespace std;
/*
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // prepare adj
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        pair<int, int> UtoV = make_pair(v, w);
        adjList[u].push_back(UtoV);
        pair<int, int> VtoU = make_pair(u, w);
        adjList[v].push_back(VtoU);
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // let's start algo

    // mark starting node key[1] = 0
    int startingNode = 1;
    key[startingNode] = 0;

    // Step 1 :
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Step 2 : find minimum and mark it true
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark mst[u] to true
        mst[u] = true;

        // Step 3:
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

*/

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // prepare adj
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        pair<int, int> UtoV = make_pair(v, w);
        adjList[u].push_back(UtoV);
        pair<int, int> VtoU = make_pair(u, w);
        adjList[v].push_back(VtoU);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // let's start algo

    // mark starting node key[1] = 0
    int startingNode = 1;
    key[startingNode] = 0;
    pq.push(make_pair(0, startingNode)); // {weight, node}

    // Step 1 :
    while (!pq.empty())
    {
        // Step 2 : find minimum and mark it true
        int u = pq.top().second;
        pq.pop();

        // mark mst[u] to true
        mst[u] = true;

        // Step 3:
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                key[v] = w;
                pq.push(make_pair(w, v));
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main()
{

    return 0;
}