#include<bits/stdc++.h>
using namespace std;

//MAX AREA OF HISTOGRAM
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


// MAX AREA OF RECTANGLE 
// THE ONLY DIFFERENCE IS THAT IN HISTOGRAM YOU CANT HAVE FIGURE THAT DOES NOT TOUCH THE GROUND BUT IN RECTANGLE YOU CAN HAVE THAT 
// THATS WHY WE ARE SENDING ROW BY ROW BY TO 'AREA' FUNCTION  
int main(vector<vector<char>>& matrix)
{
        vector<int> histo(matrix[0].size(), 0);

        int maxi =  INT_MIN;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<histo.size(); j++)
            {
                if(matrix[i][j] == '1')
                {
                    histo[j]++;//that column of the vector is being modified
                }
                else
                {
                    histo[j] = 0;
                }
            }
            maxi = max(maxi, Area(histo));
        }
        cout<< maxi;
    
        return 0;
}