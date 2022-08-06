#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
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

void bfsUtil(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node_vertex)
{
    queue<int> q;
    q.push(node_vertex);
    visited[node_vertex] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans vector
        ans.push_back(frontNode);

        // Traverse all neighbours of frontNode
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[1];
            }
        }
    }
}

vector<int> bfs(int nodes, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Prepare adj list

    prepareAdjList(adj, edges);

    // Traverse all components of a graph

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            bfsUtil(adj, visited, ans, i);
        }
    }
}

// Note -> For answer to be in sorted order ,use set in ind list instead of list..
//  For set,insert() is used