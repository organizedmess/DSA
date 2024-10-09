#include<bits/stdc++.h>
using namespace std;

bool isCyclicDfs(int node, int parent,unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited
                ,unordered_map<int, int> parentof)
{
    visited[node] = 1;

    for(auto i : adj[node]){
        
        if(visited[i] == 0)
        {
            parentof[i]=node;
            bool result = isCyclicDfs(i,node,adj,visited,parentof);
            if(result)
            {
                return true;
            }

        }
        else if (i != parentof[node])
        {
            return true;
        }   
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
{   
    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;
    unordered_map<int, int> parent;

    for(int i=0; i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bool ans=isCyclicDfs(i,-1,adj,visited,parent);
            if (ans == 1) {
              return "Yes";
            }
        }
    }
    return "No";
    
}

int main(){
    vector<vector<int>> edges;
    int n, m;
    cycleDetection(edges,n,m);

    return 0;
}