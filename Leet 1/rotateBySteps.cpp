#include<iostream>
#include<vector>
using namespace std;


void rotate(vector<int> &v,int steps){
        for(int i = 0; i < v.size()/2; i++){
           swap(v[(i+steps)%v.size()],v[i]);
        }
    }

int main(){
    system("cls");
    vector<int> v ={2,5,1,4,7};
    rotate(v,3);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}