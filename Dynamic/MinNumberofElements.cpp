#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


int minimumElements(vector<int> &num, int x)
{   
    int res = x;
    int count=0;
    sort(num.begin(),num.end());
    int n = num.size()-1;

    while( res != 0 && n >= 0 )
    {
        int max = num[n];

        if(res >= max)
        {
            res = res - max;
            count++;
        }   
        else
        {
            n--;
        }
    }

    if(n<0)return -1;
    
    return count;
}

int recursion(int x,vector<int> num)
{
    if(x==0)
        return 0;
    
    if(x<0)
        return INT_MAX;//it will nulify this branch in the min()
    
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = recursion(x - num[i], num);
        
        if(ans != INT_MAX)// becoz the branch that doesn't complete the value will be nullified
           mini = min(mini, ans+1);
        
    }
    return mini;        
}

int memoization(int x,vector<int> num,vector<int> &memo)
{
    if(x==0)
        return 0;
    
    if(x<0)
        return INT_MAX;//it will nullify this branch in the min()
    
    if(memo[x] != -1)
            return memo[x];
        
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = memoization(x - num[i], num, memo);
        
        if(ans != INT_MAX)
           mini = min(mini, ans+1);
    
    }
    
    memo[x] = mini;
    return mini; 
}

int tabulation(int x,vector<int> num)
{   
    vector<int> tab(x+1,INT_MAX);
    tab[0] = 0;

    for(int i=1; i<=x; i++)//traverses to target
    {
        for(int j=0; j<num.size(); j++)//traverses num array
        {
            if(num[j]<=i && tab[i-num[j]] != INT_MAX)//this check is necessary coz its possible for tab[i-num[j]] to be INT_MAX and adding 1 to INT_MAX 
            {                                       //will cause the space overflow causing to garbage value 
                tab[i] = min(tab[i], tab[i-num[j]] + 1);
            }
        
        }
    }
    return tab[x];
}


int main(){
    system("cls");
    int x1=10;
    vector<int> num1 = {13,17,20,19,1,8};
    int x2=5;
    vector<int> num2 = {5,6,13,8,15};
    int x3=6;
    vector<int> num3 = {17,10,5};

    cout<< minimumElements(num1,x1)<<endl;
    cout<< minimumElements(num2,x2)<<endl;
    cout<< minimumElements(num3,x3)<<endl;
    
    int ans = recursion(x3,num3);
    if(ans != INT_MAX)
    {
         cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }


    int x4 = 6; 
    vector<int> memo(x4+1,-1);


    int ans2 = memoization(x3,num3,memo);
    if(ans2 != INT_MAX)
    {
         cout<<ans2;
    }
    else
    {
        cout<<-1;
    }
    cout<<endl;
    x4 = 6; 
    
    int ans3 = tabulation(x1,num1);
    if(ans3 != INT_MAX)
    {
         cout<<ans3;
    }
    else
    {
        cout<<-1;
    }

    return 0;
}