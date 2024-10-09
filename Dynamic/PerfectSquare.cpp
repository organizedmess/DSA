#include<iostream>
#include<algorithm>
using namespace std;

int memoization(int target,vector<int> &memo){
	    
	    if(target<0){
	        return INT_MAX; 
	    }
	    if(target==0){
	       return 0;
	    }
	    if(target==1){
	        return 1;
	    }
	    int mini = target;//because this is the maximum amount of elements that will be needed 
	                    // with all elements being 1
	            
	    if(memo[target]!=-1){
            return memo[target];
	    }        
	    
	    for(int i=1; i*i<=target; i++)
	    {   
	        mini = min(mini, 1+recursion(target-(i*i),memo));
	    }
	    
	    memo[target] = mini; 
	    
	    return memo[target];
}

int tabulation(int tar){
    vector<int> tab(tar+1,INT_MAX);
    
    tab[0] = 0;
    
    for(int i=1;i<=tar;i++){
        
        for(int j=1;j*j<=tar;j++){
           
            if(i >= (j*j))
                tab[i] = min(tab[i-(j*j)] + 1, tab[i]);
        }
    }
    return tab[tar];
}

int main(){
    int target;
    vector<int> memo(target+1,-1);
    memoization(target,memo);

    return 0;
}