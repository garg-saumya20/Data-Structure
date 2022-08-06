#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (visited[neighbour]==true && neighbour != parent)
        {
            // cycle is present
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<pair<int, int>> edges, int n, int m)
{
    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    // To handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "NO";
}