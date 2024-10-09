#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2];//a is assumed to be above than b in the table
}                   // hence smaller wgt is put above     

void makeSet(vector<int> &int> &rank,int n)
{
  for (int i=0; i<n; i++)
  {
    
    rank[i] = 0;
  }
}

int findparent(int node, vector<int> &
{
  if(= node)
    return node;

   findparent([node],)

  return 
}

void merge(int pu,int pv,vector<int> &rank,vector<int> &
{

    if (rank[pu]==rank[pv])
    {
      v;
      rank[pv]++;
    }
    else if(rank[pu] > rank[pv])
    {
      u;
    }
    else
    {
      v;
    }
    
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);//vector 'edges' has been sorted wrt to wgt 
    
    vector<int> 
    vector<int> rank(n);
    makeSet(;//first we make set

    int sum=0;

    for(int i=0;i<edges.size();i++)//then we start extracting the top most nodes 
    {                           //and start either merging or ingnoring them      

      int pu = findparent(edges[i][0],
      int pv = findparent(edges[i][1],

      int wgt = edges[i][2];
      
      if(pu != pv)//parents are not same, hence no cycle 
      {
        sum += wgt;
        merge(pu,pv,rank,ing the parents
      }

    }

  return sum;
}

int main()
{
    system("cls");    
    vector<vector<int>> edges = {{1,2,6},{2,3,2},{1,3,2},{1,0,2}};
    vector<vector<int>> edges2 = {{0,1,3},{0,3,5},{1,2,1},{2,3,8}};
    int n=4;
    cout<< minimumSpanningTree(edges2,n);
    
    return 0;
}










