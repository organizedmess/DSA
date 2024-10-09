#include<bits/stdc++.h>

bool isCycle(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int, int> parentof){
    
    queue<int> q;
    q.push(node);  
    parentof[node]=-1;
    visited[node]=1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        for(int i : adj[frontNode])//i is supposed to be children of frontNode
        {
            if(visited[i] == 1 && parentof[frontNode] != i)
            {                   //visited[i] is 1 . check if i is parent of frontNode    
                return true;    //i is not the parent of frontNode hence cycle detected
            }
            
            else if(visited[i]==0)
            {
                visited[i] = 1;
                q.push(i);
                parentof[i] = frontNode;
            }
        }
    }
    return false;   
}

string cycleDetection(vector<vector<int>>& edges, int n, int m){   
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
            bool ans=isCycle(i,adj,visited,parent);
            if (ans == 1) {
              return "Yes";
            }
        }
    }//if the entire loop ran and still not once did it detect cycle 
    // so return 'no'
    return "No";
    
}


int main(){
    system("cls");
    cycleDetection(edges,n,m)


    return 0;
}