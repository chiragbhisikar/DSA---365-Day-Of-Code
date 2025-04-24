#include <bits/stdc++.h>

using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addAdj(int u, int v, bool direction)
    {
        // direction -> 0 Undirected
        // direction -> 1 Directed

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of nodes" << endl;
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected graph
        g.addAdj(u, v, 0);
    }

    g.printAdjList();
    return 0;
}