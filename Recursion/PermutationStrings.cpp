#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
        
    }
    
}


void swap(char &c1,char &c2){
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void function (int i,vector<int> nums,vector<vector<int>>& ans)
{
    if(i >= nums.size()){
        ans.push_back(nums);
        return ;
    }

    
    int j = i;//so that the combination starts with i's current position onwards.
    
    while (j<nums.size())
    {   
        swap(nums[i],nums[j]);
        function(i+1,nums,ans);        
        swap(nums[i],nums[j]);
        j++;
    }
    
}

int main(){
    system("cls");
    vector<vector<int>> ans;
    vector<int> nums = {1,2,3};
    function(0,nums,ans);
    print(ans);
    return 0;
}