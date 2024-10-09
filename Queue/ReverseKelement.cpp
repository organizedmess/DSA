#include<iostream>
#include<queue>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;//create a stack and use it to reverse the popped elements.
    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    
    while(!s.empty()){//now empty the stack and insert the reversed elements back into the queue.
        q.push(s.top());
        s.pop();
    }
    
    i=0;
    while(i<(q.size()-k))//now get the 'k'th element to '0'th position and vice versa
    {
        int val=q.front();
        q.pop();
        q.push(val);
        i++;
    }
    
    return q;
}

int main(){
    system("cls");

    return 0;
}