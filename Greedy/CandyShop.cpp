#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int k)
{
    sort(candies, candies+N);
       
    int mini = 0;
    int buy = 0;
    int free = N-1;
       
    while(buy<=free){
        mini = mini + candies[buy];
        free = free - k;
        buy++;
    }
       
    int maxi = 0;
    buy = N-1;
    free = 0;
       
    while(free<=buy){
        maxi = maxi + candies[buy];
        free = free + k;
        buy--;
    }
       
    return {mini, maxi};
}

int main()
{

}