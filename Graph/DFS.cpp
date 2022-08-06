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

void dfsUtil(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component, int node_vertex)
{

    component.push_back(node_vertex);
    visited[node_vertex] = 1;

    // har connected node k liye recursive call

    for (auto i : adj[node_vertex])
    {
        if (!visited[node_vertex])
        {
            dfsUtil(adj, visited, component, i);
        }
    }
}

vector<vector<int>> dfs(int V, int E, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;

    // Prepare adj list
    prepareAdjList(adj, edges);

    // Traverse all components of a graph
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        vector<int> component;
        if (!visited[i])
        {
            dfsUtil(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
