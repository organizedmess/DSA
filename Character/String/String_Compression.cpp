#include<iostream>
#include<vector>
#include<string> 
using namespace std;

void print(string v){       
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
        cout<<endl;
}

string compress(string s){
    string temp="";
    int i=0;
    for(int j=0;j<=s.length();j++)
    {
        if(s[i]==s[j])
        {
            continue;
        }


        else{
            int count = j-i;
            int k=0;
            std::string c = std::to_string(count);//converting the number into string
                    
                    if(count==1){
                        // temp.push_back(c[k]);
                        temp.push_back(s[i]);//pushing the character 
                    }

                    else{
                        temp.push_back(s[i]);//pushing the character 
                        
                        while(c[k]!='\0'){
                        temp.push_back(c[k]);//pushing the number if its not one 
                        k++;
                        }   
                    }

            i = j;
        }
    }
    print(temp);
    return temp;
}

int main(){
    system("cls");
    string str="abbbbbbbbbbbbbc";
    // string str="cvtt";
    compress(str);

}