#include<bits/stdc++.h>
using namespace std;

int Memoization(int i,vector<int> &arr){
    if(i<=1)
        return i;

    if(arr[i] != -1)
        return arr[i];
    

    arr[i] = Memoization(i-1,arr) + Memoization(i-2,arr);
    return arr[i];
}

int tabulationMethod(int n){
    vector<int> tab(n);

    tab[0] = 0;
    tab[1] = 1;

    for(int i=2;i<=n;i++)
    {
        int ans = tab[i-2] + tab[i-1];
        tab[i] = ans;            
    }   

    return tab[n];
}

int spaceOptimization(int n){
    int prev1 = 0;
    int prev2 = 1;

    int curr;
    for(int i=2;i<=n;i++){
        curr = prev2 + prev1;

        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}

int main()
{       
        system("cls");
        int n=8;
        vector<int> arr(n+1,-1);
        int ans1 = Memoization(n, arr);

        int ans2 = tabulationMethod(n);

        int ans3 = spaceOptimization(n);

        cout<<ans1<<" "<<ans2<<" "<<ans3;
        return 0;
}