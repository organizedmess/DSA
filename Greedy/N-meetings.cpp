#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    }
int maxMeetings(int start[], int end[], int n)
{
        vector<pair<int, int> > v;

        for(int i=0; i< n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);  
        }
        
        sort(v.begin(), v.end(), comp);
        
        int count = 1;
        int ansEnd = v[0].second;
        
        for(int i=1; i<n; i++)
        {
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        
        return count;
}

int main(){
    
}