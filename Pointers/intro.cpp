#include<iostream>
#include<vector>
using namespace std;

void update(int *x,int **y){//None of the addresses changed
    *x = *x + 1;
    // x = x + 1;
    *y = *y + 1;
} 

int main(){
    system("cls");

    int val = 5;
    int *p1 = &val;
    int **p2= &p1;
    // cout<<"before:"<<*p1<<endl;//changed
    cout<<"before:"<<p1<<endl;// changed
    cout<<"before:"<<*p2<<endl;//not changed

    update(p1,p2);
    
    // cout<<"After:"<<*p1<<endl;//changed 
    cout<<"After:"<<p1<<endl;//changed 
    cout<<"After :"<<*p2<<endl;//not changed
    
   
   
    return 0;
}