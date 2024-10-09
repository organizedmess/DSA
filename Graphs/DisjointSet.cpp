#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parentof, vector<int> &rank, int n)
{
    //simply initialising everyone as their own parent and rank=0 
    for(int i=0;i<n;i++){
        parentof[i] = i;
        rank[i] = 0;
    }
}

int Findparent(vecotr<int> parentof, int u)
{
    if(parentof[u] == u)
        return u;

    parentof[u] = Findparent(parentof, parentof[u]);
    return parentof[u];
}

void UnionSet(int u, int v, vector<int> &parentof, vector<int> rank)
{
    int pu = parentof[u]
    int pv = parentof[v];

    if(rank[pu] == rank[pv])
    {
        parentof[pu] = pv;
        rank[v]++;//this is the only case where ranks is changed 
    }
    else if(rank[pu] > rank[pv])
    {
        parentof[pv] = pu
    }
    else
    {
        parentof[pu] = pv;
    } 

}

int main(){
    int n;
    vector<int> parentof(n);
    vector<int> rank(n);
    
    makeSet();
    return 0;
}