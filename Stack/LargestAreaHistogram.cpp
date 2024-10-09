#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> firstSmallerElement(vector<int> vec){
    stack<int> s;
    s.push(-1);
    vector<int> ans(vec.size());
    
    for(int i=vec.size()-1;i>=0;i--)//started from the end
    {  int curr=vec[i];

       while(s.top() != -1 && curr<=vec[s.top()])//cant pop -1
       {
            s.pop();
       }

       ans[i]=s.top();
       s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> vec){
    stack<int> s;
    s.push(-1);
    vector<int> ans(vec.size());

    for(int i=0;i<vec.size();i++)//started from the start
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

int Area(vector<int> vec){
    vector<int> next;
    vector<int> prev;
    
    next = firstSmallerElement(vec);
    prev = prevSmallerElement(vec);

    int area=0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (next[i] == -1)//at the end
        {
            next[i] = vec.size();
        }
        int l=vec[i];
        int b=next[i]-prev[i]-1;

        int newArea=l*b;    
    
        if (area<newArea)
        {area=newArea;}
        else{area=area;}
    }
    return area;   
}

int main(){
    system("cls");
    vector<int> vec={2,1,5,6,2,3};
    cout<<Area(vec);

    return 0;
}