#include<bits/stdc++.h>
#include<map>
using namespace std;


int main(){
    system("cls");
    map<string,int> visited;
    
    int n;
    cin>>n;
    
    for (int i = 0; i < n; ++i){
        string str;
        cin>>str;
        visited[str]++;
    }

    for(auto value: visited){
        cout<<value.first<<" "<<value.second<<endl;
    }
    
    return 0;
}