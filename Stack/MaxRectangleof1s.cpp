#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> firstSmaller(int* vec,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {  int curr=vec[i];

       while(s.top() != -1 && curr<=vec[s.top()])
       {
            s.pop();
       }

       ans[i]=s.top();
       s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(int* vec,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++)
    {   int curr=vec[i];
        
        while (s.top()!= -1 && curr<=vec[s.top()])
        { 
            s.pop();
        }
        
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largestAreaRectangle(int *arr,int m){
        
    vector<int> next(m);
    next = firstSmaller(arr,m);
    
    vector<int> prev(m);
    prev = prevSmaller(arr,m);

    int area=0;
    for (int i = 0; i < m; i++){
        int l=arr[i];
        if (next[i] == -1){
            next[i]=m;
        }
        
        int b=next[i]-prev[i]-1;
        int newArea=l*b;

        if(area < newArea){
            area=newArea;
        }
        else{
            area=area;
        }
    }
    return area;
}


int MaxArea(int arr[][4],int n,int m){
    int area = largestAreaRectangle(arr[0],m);

    for (int i = 1; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]!=0)
            {
                arr[i][j]=arr[i-1][j] + arr[i][j];
            }
            else
            {
                arr[i][j]=0;
            }
        }

        int newArea = largestAreaRectangle(arr[i],m);
        if(area < newArea){
            area=newArea;
        }
        else{
            area=area;
        }
    }
    return area;
}

int main(){
    system("cls");
    int arr[4][4]={{0,1,1,0},
                   {1,1,1,1},
                   {1,1,1,1},
                   {1,1,0,0}};

    cout<<MaxArea(arr,4,4);

    return 0;
}