#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void print(vector<int> v){
        for(int i=0; i<v.size();i++)
            {cout<<v[i]<<" ";}
            cout<<endl;
}

vector<int> method(int arr[],int n,int k)
{
    vector<int> ans;
    deque<int> d;
    //creating a base 
    int j=0;
    while (j<k)
    {
        if (arr[j]<0)
        {
            d.push_back(j);
        }
        j++;
    }
    //PUSH IN ANS FOR BASE WINDOW
    if (d.size()>0)
    {
        ans.push_back(arr[d.front()]);
    }
    else
    {
            ans.push_back(0);
    }
    
    for (int i = k; i < n; i++)
    {
        if (i-d.front()>=k)
        {
            d.pop_front();
        }
        
        if (arr[i]<0)
        {
            d.push_back(i);
        }
        
        if (d.size()>0)
        {   
            ans.push_back(arr[d.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    system("cls");
    int arr[]={2,-1,-2,3,-3,-4,3,-5};

    vector<int> res=method(arr,8,2);
    print(res);
    return 0;
}