#include<bits/stdc++.h>

bool isCyclic(int node, unordered_map<int,bool> &dfsvisited, unordered_map<int,list<int>> adj,unordered_map<int,bool> &visited)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for(auto i: adj[node])
    {
        if(visited[i] == false)
        {    
            bool ans = isCyclic(i, dfsvisited, adj, visited);
            if(ans==true)
            {
                return true;
            }
        }
        else if(dfsvisited[i] == true)
        {
           return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}   

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
    unordered_map<int,list<int>> adj;
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
    
        adj[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;//the only difference between this and Undirected cycle detection using Dfs
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {   
            bool ans = isCyclic(i, dfsvisited, adj, visited);
            if(ans == true)
            {
                return true;
            }
        }
    
    }
    return false;
    
}