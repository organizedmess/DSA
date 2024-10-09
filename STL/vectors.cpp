#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
        for(int i=0; i<v.size();i++)
            {cout<<v[i]<<" ";}
            cout<<endl;
}
void func1(vector<int> &vec){
        // for(int i=0;i<vec.size();i++){
        // }
        vec.push_back(2);
}

int main(){
    system("cls");
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    // vector<int> v;
    // cout<<v.capacity()<<endl;
    // int n=5;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     // cout<<endl;
    //      v.push_back(x);//  O(1)
    // }
    // cout<<v.capacity()<<endl;
    // print(v);
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    vector<int> v3(10,4);//vector of 10 size with all values being "4"
    print(v3);
    func1(v3);
    print(v3);
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    vector<int> &v2=v3;//copying value is a hefty task: O(n) for n values. Hence prefer refrencing.
    func1(v3);
    print(v3);
    print(v2);

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}
