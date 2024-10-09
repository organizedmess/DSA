#include<bits/stdc++.h>
using namespace std;

int signum(int a,int b){
    if(a == b){return 0;}
    else if(a > b){return 1;}
    else if(a < b){return -1;}
    return 0;
}

void Cases(int element,priority_queue<int> &maxi,priority_queue<int, vector<int> ,greater<int>> &mini,int &median)
{
    switch (signum(maxi.size(),mini.size()))
        {
            case 0 : if(element > median)
                    {
                        mini.push(element);
                        median = mini.top();
                    }
                    else
                    {
                        maxi.push(element);
                        median = maxi.top();
                    }
            break;

            case 1 : if(element > median)
                    {
                        mini.push(element);
                        median = (maxi.top() + mini.top())/2;
                    }
                    else
                    {   
                        mini.push(maxi.top());
                        maxi.pop();
                        maxi.push(element);
                        median = (maxi.top() + mini.top())/2;
                    }
            break;

            case -1 : if(element > median)
                    {   
                        maxi.push(mini.top());
                        mini.pop();
                        mini.push(element);
                        median = (maxi.top() + mini.top())/2;
                    }
                    else
                    {   
                        maxi.push(element);
                        median = (maxi.top() + mini.top())/2;
                    }
            break;    
        }

}

vector<int> FindMedian(vector<int> stream){
    vector<int> ans;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    int median = 0;
    for (int i = 0; i < stream.size(); i++)
    {
        Cases(stream[i],maxi,mini,median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    system("cls");
    vector <int> v = {2,3,4};
    vector <int> res = FindMedian(v);
    
    for (auto &&i : v)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
