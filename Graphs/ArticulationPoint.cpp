#include<bits/stdc++.h>
using namespace std;

void articulation(int node,int parent,int &timer,vector<int> &low,vector<int> &disc,vector<bool> &visited,vector<int> &ans,unordered_map<int,list<int>> &adj)
{
    visited[node] = 1;
    low[node] = disc[node] = timer++;
    int child = 0;
    
    for(auto i: adj[node]){
        if(i == parent){
            continue;
        }

        if(visited[i] == 0)
        {   
            articulation(i,node,timer,low,disc,visited,ans,adj);
            low[node] = min(low[node],low[i]);
             // articulation point
            if(low[i] >= disc[node] && parent != -1)
            {//low[i] >= disc[node] because unlike bridges, we dont need 'i' to be accessible strictly before 'node'  
            //becoz even if their accessible time is same, removing 'node' will break the graph at the exact same time 
            //as we dont need to travel the edge node->i unlike in bridges
                 ans[node] = 1;
            }
            child++;//this will help is analysing the root node
        }
        else
        {   //back-Edge
           low[node] = min(low[node],disc[i]);
        }
    }

    //this condition is for root node as it might also be an articulation point
    if(parent == -1 && child > 1)
        ans[node] = 1;
        
}

int main(){

    vector<pair<int,int> > edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    int n=5;
    int e=5;

    unordered_map<int,list<int>> adj;
    for (int i=0;i<edges.size(); i++)
    {
        int u= edges[i].first;
        int v= edges[i].second;
    
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> visited(n,0);

    vector<int> ans(n,0);
    int timer = 0;
    int parent = -1;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            articulation(i,parent,timer,low,disc,visited,ans,adj);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(ans[i] != 0){
            cout<<i<<" ";
        }
    }

    return 0;
}