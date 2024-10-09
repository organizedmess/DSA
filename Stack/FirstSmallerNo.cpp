#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> func(vector<int> vec){
    stack<int> st;
    st.push(-1);
    
    int i=vec.size()-1;

    while(i >= 0)
    {   int curr = vec[i];
        while(curr <= st.top())
        {   
            st.pop();
        }
        vec[i]=st.top();
        st.push(curr);
        i--;
    }

    return vec;
} 

void print(vector<int> v){
        for(int i=0; i<v.size();i++)
            {cout<<v[i]<<" ";}
            cout<<endl;
}

int main(){
    system("cls");

    vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(3);

    print(vec);
    print(func(vec));
    
    return 0;
}