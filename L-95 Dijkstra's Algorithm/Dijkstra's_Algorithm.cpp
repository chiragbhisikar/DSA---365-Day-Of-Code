#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // prepare adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        pair<int, int> UtoV = make_pair(v, weight);
        adjList[u].push_back(UtoV);
        pair<int, int> VtoU = make_pair(u, weight);
        adjList[u].push_back(VtoU);
    }

    // create array of distance with infinite value
    vector<int> distance(vertices);
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }

    // create set on basis <distance, node>
    set<pair<int, int>> st;

    // intialize distance and set with source node
    distance[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch the top
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top node
        st.erase(st.begin());

        for (auto neighbour : adjList[topNode])
        {
            int totalDistance = nodeDistance + neighbour.second;

            // if distance array distance is greater than totalDistance Then Update It
            if (totalDistance < distance[neighbour.first])
            {
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                distance[neighbour.first] = totalDistance;
                // record push in set
                st.insert(make_pair(totalDistance, neighbour.first));
            }
        }
    }

    return distance;
}
int main()
{

    return 0;
}