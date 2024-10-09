#include<iostream>
#include <vector>
using namespace std;


void print(vector<vector<int> > v){
    
    for (int j = 0; j < v.size(); j++)
        {
        for (int i = 0; i < v[j].size() ; i++)
        {
            cout<< v[j][i];
        }
            cout<<endl;
        }
} 
            
       

void subset(vector<int> arr,int i,vector<int> v,vector<vector<int> >& out){

    if (i >= arr.size())
    {   
        out.push_back(v);
        return ;  
    }
    
    //case 1 :exclude
    subset(arr,i+1,v,out);

    //case 2 :include
    int element = arr[i];
    v.push_back(element);
    subset(arr,i+1,v,out);

}
    
int main(){
    system("cls");
    vector<int> array = {1,2,3};
    vector<int> v;
    vector<vector<int> > out;
    subset(array,0,v,out);
    print(out);
    return 0;
}


