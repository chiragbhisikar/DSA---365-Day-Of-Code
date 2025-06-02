#include <bits/stdc++.h>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // prepare indegree of all
    vector<int> indegree(v);

    for (int i = 0; i < e; i++)
    {
        int v = edges[i][1];

        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
