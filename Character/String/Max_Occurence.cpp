#include<iostream>
using namespace std;

char getMaxOccuringChar(string str){
    int arr[26]={0};
    for(int i =0;i<str.size();i++){
        int num = str[i] - 'a';
        arr[num]++;
    }
    
    int maxi =-1;
    int ans = 0;
    for(int j=0;j<26;j++){
        if(maxi<arr[j]){
            ans =j;
            maxi=arr[j];}
    else{
        continue;}
    }
        return ans + 'a';
    }


void print(string v){       
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
            cout<<endl;
}
int main(){
    system("cls");
    string s ="test sample people";
    spaceremove(s);
    print(s);
    // cout<<getMaxOccuringChar(s);

}