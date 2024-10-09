#include<bits/stdc++.h>
#include<vector>
using namespace std;

void swab(string &s,int i,int r){
    while(i<r){
        char temp = s[i];
        s[i] = s[r-1];
        s[r-1] = temp ;
        i++;
        r--;
}}


string revWords(string &v){
    int i=0;
        for(int r = 0; r <= v.size(); r++){

                if(v[r]!=' ' && v[r]!='\0'){
                        continue;
                } 
                else{   
                        swab(v,i,r);
                        i = r+1 ;
                        // i++;
                }
}
    return v;
    }

void print(string v){       
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
            cout<<endl;
}



// void reverseString(vector<string>& s){
        
        
//     int i=0;
//     while(i<s.size()-i){
//         string temp = s[i];
//         s[i] = s[s.size()-1-i];
//         s[s.size()-1-i] = temp;
//         i++;
//         // swab(s[i],s[count-1-i]);
//         }
//     }


// char lowercase(char ch){
//     if(ch>='a' && ch<='z'){
//     return ch;
//     }
//     else{
//     char temp= ch - 'A' + 'a';
//     return temp;
//     }
// }

// bool palindromeCheck(vector<char> s){
//     // bool true;
//     int i=0;
//     int e=s.size()-1;
//     while (i<=e){
//     if(lowercase(s[i])!=lowercase(s[e])){
//         return false;
//         // break;
//     }
//     else{
//         i++;
//         e--;
//     }
//         return true;
//     }
// }

int main(){ 
    system("cls");
    vector<string> str ={"H","e","l","l","o"};
    vector<string> str2 ={"H","e","l","e","h"};
    vector<char> str3 ={'H','e','l','e','h'};
    // vector <string>str4 = {"H","e","l","l","o"," ","W","o","r","l","d"}; 
    string str4 = "Hello World BY Dhruv"; 
    // reverseString(str);
    // print(str);
    // cout<<palindromeCheck(str3);
    revWords(str4);
    print(str4);

    }
