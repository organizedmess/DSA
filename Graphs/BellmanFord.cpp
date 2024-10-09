#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n+1,1e9);//point of conflict
    dist[src] = 0;
    //n-1 cycles
    for(int i=1; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wgt = edges[j][2];

            if(dist[u]!=1e9 && ((dist[u] + wgt) < dist[v]))
            {
                dist[v] = dist[u] + wgt;
            }
        }
    }

    // nth cycle
    bool flag = 0;
    for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wgt = edges[j][2];

            if(dist[u]!=1e9 && ((dist[u] + wgt) < dist[v]))
            {
                flag = 1;//if this condition hits even once, it means neg cycle exists
            }
        }

    if(flag == 0)
        {
            return dist[dest];//returning the min distance becoz negative cycle doesn't exist. 
        } 
    else
        {
           return -1;
        }

}

int main(){
    system("cls");

    cout<<bellmonFord();
    return 0;
}