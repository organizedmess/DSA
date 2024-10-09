#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
        cout<<endl;
    }
}

void function(string digits,vector<string>& ans,string output,int index,string mapping[]){
    
    if(index>=digits.length()){ //Base case
        ans.push_back(output);
        return;   
    }
            
        
    
    int number = digits[index] - '0';//This is to convert the "23" to numbers '2' and '3'.
    string value = mapping[number];//Finally the string that will have the permutations.


for(int j=0;j<value.length(); j++)//traverse through 2nd string.
    {
        output.push_back(value[j]);
        function(digits,ans,output,index+1,mapping);//traverse through 1st string.
        output.pop_back();
    }
    
}


    
int main(){
    system("cls");
    string digits ="23";
    int index = 0;//This points to the string of digits.
    
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    string output = "";
    vector<string> ans;
    
    function(digits,ans,output,index,mapping);
    print(ans);
    return 0;
}