#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kLargest(vector<int> v,int k)
{

    priority_queue<int,vector<int>, greater<int> > pq;

    for (int i = 0; i < v.size(); i++)
    {   
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];

            if (pq.size() < k)//andha push kro abhi toh
            {
                pq.push(sum);
            }
            else
            { 
                if (pq.top() < sum)//agar pq.top() chhota h sum se iska mtlb pq.top() kth largest nhi h vo shayad k+n larget hoga kyonki ussey badey 'k' sums mil gaye hn
                {
                    pq.pop();
                    pq.push(sum);
                }
            }   
        }
    }
    return pq.top();
}

int main(){
    system("cls");
    vector<int> vec = {3,6,1,8,2};
    int k = 3;

    cout<<kLargest(vec,k);
    return 0;
}