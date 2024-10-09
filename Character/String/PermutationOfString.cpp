#include<iostream>
#include<vector>
using namespace std;

bool checkEqual(int arr1[26],int arr2[26]){
    for (int i = 0; i < 26; i++)
        {
        if (arr1[i] != arr2[i])
            {
                return 0; //return stops the function 
            }
        }
                return 1;
    }
bool CheckInclusion(string str1,string str2){
    
// smaller string
    int count1[26]={0};
    for(int i=0;i<str1.length();i++){
        int num = (str1[i] - 'a');
        count1[num]++; 
    }
// bigger string:only comparing it per the size of smaller string,hence the "window".
    int count2[26]={0};
    int i=0 ;
    while (i<str1.length())
    {
        int num = (str2[i] - 'a');
        count2[num]++;
        i++;
    }
    if(checkEqual(count1,count2))
        return 1;
    //updating the window  
    while(i<str2.length())
    {   
       int num = (str2[i] - 'a');
       count2[num]++;

        num = (str2[i-str1.length()]) - 'a';
        count2[num]--;

        i++;
    
    if(checkEqual(count1,count2))
        return 1;
    }
        return 0;
}

int main(){
    system("cls");
    string str = "eibonol";
    string prt = "obnq";
    cout<<CheckInclusion(prt,str) ;
}