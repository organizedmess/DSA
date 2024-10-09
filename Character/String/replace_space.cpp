#include<iostream>
using namespace std;

void print(string v){       
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
        cout<<endl;
}

void spaceremove(string& s){
    string temp = "";//because strings are immutable. 
    for (int i = 0; i < s.size(); i++)
        {
            if (s[i]==' '){
                temp.push_back('@');   
                temp.push_back('4');   
                temp.push_back('0');   
        }
            else{
                temp.push_back(s[i]);
        }
        }
    print(temp);
    }

int main(){
    system("cls");
    string str="Let it be known.";
    spaceremove(str);
    print(str);
}