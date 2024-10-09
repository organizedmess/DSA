#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr)
{   
    int unique = 0;
    for(int i: arr)
    {
        unique ^= i;
    }
    return unique;
}

int main()
{
    system("cls");
    vector<int> arr = {2,3,3,4,2,6,4};
    cout<<func(arr);
}