#include<iostream>
#include<vector>
using namespace std;

int recursion(vector<int> wgt, vector<int> val, int n, int capacity)
{
	if(n==0)
	{
        if (wgt[0] <= capacity) 
		{
        	return val[0];
        } 
		else
		{	
        	return 0;
        }
    }
	
	int includeVal = 0;

		if (wgt[n] <= capacity)
		{
          includeVal = val[n] + memoization(wgt,val,n-1,capacity-wgt[n]);
        }
        
		int excludeVal = memoization(wgt,val,n-1,capacity);
	
	int ans = max(includeVal,excludeVal); 

	return ans;
}

int memoization(vector<int> wgt, vector<int> val, int n, int capacity,vector<vector<int>> &memo)
{
	if(n==0)
	{
        if (wgt[0] <= capacity) 
		{
        	return val[0];
        } 
		else
		{	
        	return 0;
        }
    }

	if(memo[n][capacity]!=-1)
		return memo[n][capacity];
	
	
	int includeVal = 0;

		if (wgt[n] <= capacity)
		{
          includeVal = val[n] + memoization(wgt,val,n-1,capacity-wgt[n],memo);
        }
        
	int excludeVal = memoization(wgt,val,n-1,capacity,memo);
	
	int ans = memo[n][capacity] = max(includeVal,excludeVal); 

	return ans;
}

int tabulation(vector<int> wgt, vector<int> val, int n, int capacity)
{
	vector<vector<int> > tab(n,vector<int>(capacity+1,0));

	// base case 
	//we are filling the inside vector of 0 index with wgt[0] 
	
	for(int w=wgt[0];w<=capacity;w++)
	{
		if(wgt[0] <= capacity)
		{
				tab[0][w] = val[0];
		}	
        else
		{
            	tab[0][w] = 0;
        }
	}

	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=capacity;w++)
		{
			int includeVal = 0;
			
			if(wgt[i]<=w)
				includeVal = val[i] +  tab[i-1][w - wgt[i]];

			int excludeVal = tab[i-1][w]; 

			tab[i][w] = max(includeVal,excludeVal);
		}
	}
	return tab[n-1][capacity];
}

int SpaceOptimizedTabulation(vector<int> wgt, vector<int> val, int n, int capacity)
{
	//instead of creating the entire 2-d array we only create 2-1D arrays 
	//we only ever need the array 2 rows at a time 
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);

	// base case 
	//we are filling the inside vector of 0 index with wgt[0] 
	
	for(int w=wgt[0];w<=capacity;w++)
	{
		if(wgt[0] <= capacity)
		{
			prev[w] = val[0];//this is array's only job is to store wgt[0]
		}	//if there is capacity enough to store it 
        else
		{
            prev[w] = 0;
        }
	}
	for(int i=1;i<n;i++)
    {
        for (int w = 0; w <= capacity; w++)
		{
            int includeVal = 0;

            if (wgt[i] <= w)
              includeVal = val[i] + prev[w - wgt[i]];

			  
            int excludeVal = prev[w];

            curr[w] = max(includeVal, excludeVal);
        }
		prev = curr;//transferring the values so as to use prev in the next loop 
    }
        
	return prev[capacity];
}

int SingleVector(vector<int> wgt, vector<int> val, int n, int capacity)
{
	vector<int> curr(capacity+1,0);
	// base case 
	//we are filling the inside vector of 0 index with wgt[0] 
	for(int w=wgt[0];w<=capacity;w++)
	{
		if(wgt[0] <= capacity)
		{
				curr[w] = val[0];
		}	
        else
		{
            	curr[w] = 0;
        }
	}

	for(int i=1;i<n;i++)
	{
		for(int w=capacity; w>=0;w--)
		{
			int includeVal = 0;
			
			if(wgt[i]<=w)
				includeVal = val[i] +  curr[w - wgt[i]];

			int excludeVal = curr[w]; 

			curr[w] = max(includeVal,excludeVal);
		}
	}
	return curr[capacity];
}

int main(){
    system("cls");

    return 0;
}