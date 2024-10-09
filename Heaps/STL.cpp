#include<iostream> 
#include<queue>
using namespace std;

int main(){
    system("cls");
    

    //Max-Heap by default
    cout<<"Max Heap starts from here:"<<endl;
    priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(11);
    pq.push(9);
    pq.push(20);
    pq.push(1);

    cout<<pq.top()<<endl;//giving the highest number.
    pq.pop();
    cout<<pq.top()<<endl;//giving the highest number.

    // MIN HEAP
    cout<<"Min Heap starts from here:"<<endl;
    priority_queue<int, vector<int>, greater<int> > minheap;
    minheap.push(5);
    minheap.push(3);
    minheap.push(11);
    minheap.push(9);
    minheap.push(20);
    minheap.push(1);
    minheap.push(4);

    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top()<<endl;
    
    return 0;
}