#include<bits/stdc++.h>
using namespace std;

// this function is used to find topological sort
void TopologicalSort(int node, vector<bool>&visited, vector<pair<int,int> > adj[],stack<int> &s)
{
    visited[node] = 1;

    for(auto i: adj[node])
    {
        if(visited[i.first] == 0)
        {
            solve(i.first,visited,adj,s);
        }   
    }
    s.push(node);//as this is the last process 
                // the last number will be the first one to get inside
                //so by the end the numbers will get pushed in the reverse order
                //of them getting called 
}  

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
{
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// creating adjaceny list
    vector<pair<int,int> > adj[N];
        
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wgt = edges[i][2];// important : this is the weight for every edge  
           
        adj[u].push_back({v,wgt});
    }
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// finding topological sort
    vector<bool> visited(N);
    stack<int> s;
    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
        {   
            TopologicalSort(i,visited, adj, s);
        }
    }
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    
    // a vector of N size with all elements being inf/very big number
    vector<int> dis(N,1e9);
    int src = 0;

    dis[src]=0;
    
    // topological sort stack is used here 
    while(!s.empty())
    {
        int top = s.top();
        s.pop();

            if(dis[top]!=1e9)//this if condition is for the case when our source node is not at the top of the topological order,i.e there are some unreachable nodes 
            {               //and the distance to them remain infinity 
                for(auto i: adj[top])
                {
                    int v = i.first;
                    int wgt = i.second;// weight between u and v 
                    if(dis[top] + wgt < dis[v])// distance from source to top + wgt(cost of going to top to v) < distance from source to v 
                    { 
                        dis[v] = dis[top] + wgt;// relaxing the vertices
                    }
                }
            }
    }

    //this was asked in the question to print -1 instead of infinity
    for(int i = 0; i < N; i++){
        if (dis[i] == 1e9) dis[i] = -1;
    }

    return dis;// this is a vector that has the shortest distance from source to all the nodes     
}

int main(){

    shortestPath(N,M,edges);
    // 'edges' here has three columns instead of two , third column representing the wgt between the nodes in first and second column.  
    return 0;
}