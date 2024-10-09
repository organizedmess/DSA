#include<iostream>
#include<queue>
using namespace std;



int main(){
    system("cls");
    queue<int> q;

    q.push(5);
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
    q.push(8);
    q.push(1);
    q.push(5);
    cout<<q.front();
    return 0;
}