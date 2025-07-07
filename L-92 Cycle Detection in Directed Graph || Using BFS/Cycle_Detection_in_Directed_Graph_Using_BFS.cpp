#include <bits/stdc++.h>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // prepare adjuncecy list and indegree
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(n);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<bool> visited(n);
    int count = 0;

    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (count == n)
    {
        return 0;
    }
    // invalid topological Sort Means Cycle Detect
    else
    {
        return 1;
    }

    return 0;
}

int main()
{

    return 0;
}