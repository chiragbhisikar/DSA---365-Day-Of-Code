#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // prepare adjuncency list
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // do bfs
    vector<bool> visited(n + 1);
    vector<int> parent(n + 1);
    queue<int> q;

    q.push(s);
    visited[s] = false;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // find path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{

    return 0;
}