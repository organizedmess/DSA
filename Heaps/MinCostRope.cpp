#include<iostream> 
#include<queue> 
#include<vector> 
using namespace std;

int minCost(vector<int> arr) {
        priority_queue<int,vector<int> ,greater<int> > pq;
        
        int cost =0;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cost += a + b;
            pq.push(a+b);    
        }
    return cost;
}

int main(){
    system("cls");
    vector<int> v ={4,3,2,6};
    cout<<minCost(v);
    return 0;
}

