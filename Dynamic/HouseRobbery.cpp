#include <bits/stdc++.h> 
using namespace std;

long long int spaceOptimization(vector<int> nums)
{
    long long int n = nums.size();

    long long int prev2=0;
    long long int prev1=nums[1];

    long long int curr;
    
    for(int i=2;i<n;i++)
    {
        curr = max(prev2+nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

long long int houseRobber(vector<int>& val)
{   
    int n = val.size();
    vector<int> first(n-1) ;
    vector<int> second(n-1) ;

  if(n==1){
    return val[0];
  }
  
    for (int i = 0; i < n; i++)
    {
        
      if (i!=0)
        first.push_back(val[i]);

      if (i!=n-1)
        second.push_back(val[i]);

    }

    return max(spaceOptimization(first),spaceOptimization(second));

}

int main(){
    vector<int> val = {};
    cout<<houseRobber(val);
    return 0;
}