#include <bits/stdc++.h> 
using namespace std;


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map< int,list<pair<int,int>>> adj;
    for(int i=0; i<m ;i++)
    {
        int u = g[i].first.first; 
        int v = g[i].first.second; 
        int wgt = g[i].second; 
    
        adj[u].push_back(make_pair(v,wgt));
        adj[v].push_back(make_pair(u,wgt));
    }

    vector<bool> MST(n+1,0);// is the node inside mst
    vector<int> key(n+1,INT_MAX);//distance from the current node 
    vector<int> parentof(n+1,-1);//parent of the node

    int src = 1;
    key[src] = 0;
    parentof[src] = -1;

  for(int i=1;i<n;i++)//this represents the number of times we are going inside
  {                  // the 'key' array to extract the node with minimum edge 
        int mini=INT_MAX; 
        int u=0;

        //you are finding minimum in KEY array i.e,
        //(vertex with minimum wgt && still not a part of MST) 
        for (int j=1;j<=n;j++)
        {
          if(MST[j] == 0 && key[j] < mini)
          {
            mini = key[j];
            u = j;
          }
        }
        
        MST[u] = 1;//you make a vertex part of MST when you get to study all its edges/neighbours 
                  //which you are doing down here 

        for(auto neighbour: adj[u])//here we will discuss the prospects of U's effect on its neighbours
        {
           int v = neighbour.first;
           int wgt = neighbour.second;
           
           if (MST[v] == 0 && key[v] > wgt) // key[v] > wgt represents that the previuos ways of reaching 'v'
            {                               // are more costly than reaching 'v' from 'u' hence we will include this edge
                                            // and overwrite the previus one 
                parentof[v] = u;
                key[v] = wgt;
              // this is how we are filling key array
            } // as key does not store the distance but the minimum wgt 
        }     // of all the edges connecting that vertex 
    }
    

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++)
    {
      ans.push_back({{parentof[i], i}, key[i]});
    }

    return ans;
}

int main{

    vector<pair<pair<int, int>, int>>  mst = calculatePrimsMST();

    return 0;
}
