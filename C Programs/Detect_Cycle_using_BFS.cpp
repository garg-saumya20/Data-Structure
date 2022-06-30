#include<iostream>
using namespace std;
#include <list>
#include <unordered_map>
#include <queue>

class detect_Cycle_using_BFS
{
public:
    bool isCycleBFS(int source, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        queue<int> q;
        parent[source] = -1;
        visited[source] = 1;
        q.push(source);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto neighbour : adj[x])
            {
                if (visited[neighbour] == 1 && neighbour != parent[x])
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                    parent[neighbour] = x;
                }
            }
          
        }
          return false;
    }
    string cycleDetection(vector<vector<int>> &edges, int n, int m)
    {
        // Write your code here.
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool ans = isCycleBFS(i, visited, adj);
                if (ans == 1)
                {
                    return "Yes";
                }
            }
        }
        return "No";
    }
};
int main()
{
    detect_Cycle_using_BFS g;
    vector<vector<int>> edges={{1,2},{2,3}};
    string ans=g.cycleDetection(edges,3,3);
  cout<<ans;
    return 1;

}
