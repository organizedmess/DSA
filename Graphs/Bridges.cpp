#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void solve(int node, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<vector<int> > &ans,
            int &timer, int parent, unordered_map<int,list<int>> &adj)
{
    visited[node] = 1;
    low[node] = disc[node] = timer++;

    for(auto i: adj[node])
    {
        if(parent==i)
        {// we simply ignore the parent
            continue;
        }    

        if(visited[i]==0)
        {   
            solve(i,low,disc,visited,ans,timer,node,adj);  

            // rechecking the nodes while backtracking 
            low[node] = min(low[node],low[i]);//the lowest time possible neighbour of node is stored here 
            

            //checking if this edge is a bridge
            if(low[i]>disc[node])// i says "if you removed the path between us then the lowest time to reach me will be more and hence "
            {   // it means that there is no back-edge for the i hence removing the edge node-> i will break the 'i'th node into another component 
                vector<int> res;
                res.push_back(node);
                res.push_back(i);
                ans.push_back(res);
            } 
        }
        else//i has aloready been visited before meaning it is connected to components before the 'node'
        {   
            //BACK-EDGE
            low[node] = min(low[node],disc[i]);//we already know that low[node] contains the lowest possible time of its neighbours and disc[i] contains the i's discovery time 
        }// hence the back-edge should contain whichever is minimum of these two parameters 
    }   
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) 
{
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
    
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    int timer = 0 ;
    vector<int> low(v,-1);//this contains the discovery time of neighbour with lowest discovery time of all the neighbours
    vector<int> disc(v,-1);
    vector<bool> visited(v,0);

    int parent = -1;

    vector<vector<int> > ans;

    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            solve(i,low,disc,visited,ans,timer,parent,adj);
        }
    }
    return ans;
}

int main(){
    system("cls");
    findBridges();

    return 0;
}