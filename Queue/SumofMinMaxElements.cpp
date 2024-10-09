#include<iostream>
#include<queue>
using namespace std;

int solve(int* arr,int n,int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    //first k elements sum
    for (int i = 0; i < k; i++)
    {   
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();//making a decreasing order queue

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();//making an increasing order queue 
        
        maxi.push_back(i);
        mini.push_back(i);
    }

    int sum=0;
    sum += arr[maxi.front()] + arr[mini.front()];

    //now lets get inside the array
    for (int i = k; i < n; i++)
    {   
        //phle toh uss bande ko hta do jo range se bahar jaa chuka hai
        //removal
        while (!maxi.empty() && i - maxi.front() >=k)
            maxi.pop_front();
        //maxi.front() stores an index 
        
        while (!mini.empty() && i - mini.front() >=k)
            mini.pop_front();
        //mini.front() stores an index 
        
        
        
        //addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();//making a decreasing order queue 
    

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();//making an increasing order queue 
      

        maxi.push_back(i);//everyone gets alloted in the dequeue but only on the right place acc to the order
        mini.push_back(i);//everyone gets alloted in the dequeue but only on the right place acc to the order
    
        //sum is updated for every iteration
        sum += arr[maxi.front()] + arr[mini.front()];
    }
    return sum;
}

int main(){
    system("cls");
    

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    
    cout << solve(arr, 7, k) << endl;

    return 0;
}