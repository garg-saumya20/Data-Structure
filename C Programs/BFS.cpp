
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {

        unordered_map<int, bool> visited;
        vector<int> v;
        queue<int> q;

        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            v.push_back(x);
            for (auto i : adj[x])
            {
                if (visited[i] == false)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return v;
    }
};



// #include<unordered_map>;
// #include<list>
// #include<vector>;
// #include<queue>
// vector<int> BFS(int vertex, vector<pair<int, int>> edges)
// {
//     // Write your code here
//     unordered_map<int,list<int>> adj;
//     unordered_map<int,bool> visited;
//     vector<int> v;
//     queue<int> q;
//     for(int i=0;i<edges.size();i++)
//     {
//         int u=edges[i].first;
//         int v=edges[i].second;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     q.push(vertex);
//     visited[vertex]=true;
//     while(!q.empty())
//     {
//         int x=q.front();
//         q.pop();
//         v.push_back(x);
//         for(auto i:adj[x])
//         {
//             if(visited[i]==false)
//             {
//                 q.push(i);
//                 visited[i]=true;
//             }
//         }
//     }
//     return v;
// }