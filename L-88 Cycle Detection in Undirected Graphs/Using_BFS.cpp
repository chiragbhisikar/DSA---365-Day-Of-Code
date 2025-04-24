#include <bits/stdc++.h>

using namespace std;

bool isCycleBFS(int src,
                vector<int> &visited,
                vector<int> &parent,
                unordered_map<int, list<int>> adjList)
{

    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;

    // preparing adjList
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // cout << u << v << endl;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // printing adjList
    /*
    for (auto i : adjList)
    {
        cout << i.first << " -> ";

        for (auto j : i.second)
        {
            cout << j << " , ";
        }
        cout << endl;
    }
    */

    // bfs traversal
    vector<int> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleBFS(i, visited, parent, adjList);

            if (ans == true)
                return "Yes";
        }
    }

    return "No";
}

int main()
{

    return 0;
}
