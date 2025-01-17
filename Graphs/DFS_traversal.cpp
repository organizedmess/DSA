#include<bits/stdc++.h>

void dfs(int node,unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj,vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1 ;

    for(auto i: adj[node])
    {
        if(visited[i] == 0)
        {   
            dfs(i,visited,adj,component);
        }
    }
 
}   

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;

    for(int i=0; i<edges.size(); i++)
    {   
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;

    for(int i=0;i<V;i++)
    {
        if(visited[i]==0)
        {
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int V,E;
    vector<vector<int>> edges;
    depthFirstSearch(V,E,edges);
    return 0;
}