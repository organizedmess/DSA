#include<iostream>
#include<queue>
using namespace std;

int k_smallest(int arr[],int k,int n){   
   priority_queue<int> pq;
// this will act like a reverse sorted array and if pq's size is k then the top most element 
// will give the kth smallest element(then k-1 smallest , k-2 smallest......smallest element)  
    int i;
    for (i = 0; i <= k ; i++)
        {//traversing the array from 0 to k
            pq.push(arr[i]);
        }
    //Heap is created 
   
   //now we compare it with rest of the array 
    while (i<n)//i starts from k
    {    // traversing the array from k to n

        // size of pq will always remain constant 'k'
        if (arr[i] < pq.top())
        {
        //since pq consists of 'k' array elements and if there is an element in the rest of the array that is smaller than the pq's front( since it is the biggest of pq )
        //then that element deserves its place into the pq as     
            pq.pop();
            pq.push(arr[i]);//every push operation will result in rearrangement of Heap 
            //hence T.C= O(k*logn)
            //k times we had to heapify
        }
        i++;
    }

    int ans = pq.top();
    return ans;    

}

int main(){
    system("cls");
    int arr[5] = {55,53,54,52,50};
    int k = 4;
    cout<<k_smallest(arr,k-1,5);
    return 0;
}