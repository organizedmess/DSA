#include<iostream> 
using namespace std;


void swapp(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void solve(int *arr,int n,int i){
    
    int largest = i;
    int left = 2*i ;
    int right = 2*i + 1 ;
        //if you look closely at the 'if' conditions below, you will realize that the 'i'th is actually 
        //swapping with the larger of the two child becoz if arr[left] > arr[right] then the 2nd condition wont be executed.
        //becoz largest = left by that point.
         
        if (left < n && arr[largest] < arr[left])
            largest = left;
        // left/right < n becoz at n, the swapped value is placed
        if (right < n && arr[largest] < arr[right])
            largest = right;
        
        
        if (i != largest)//checking if the value of has been changed coz then it would mean that the array needed to change
        {               //to become a heap
            swapp(arr[i],arr[largest]);
            solve(arr,n,largest);
        }
        
}
void Heapify(int *arr,int n){

    for (int i = n/2; i>0 ; i--)
    {
        solve(arr,n,i);//sending the non leaf nodes one by one from the below 
    }                       //every call rearranges the tree below the node sent according to the HEAP data structure
                           // hence HEAPYFIYING
    return ;
}

void HeapSort(int arr[],int n){
    int size = n;

    while (size > 1)//when size reaches 1 by then the array is already sorted 
    {   //step 1
        swapp(arr[1],arr[size]);
        
        //step 2
        Heapify(arr,size);
        
        size--;
    }
    
}

int main(){
    system("cls");
    int arr[6] = {-1,55,53,54,52,50};
    int n = 5;//only that much we can actually use becoz of '0'th index not being available
    
    //sorting the heap array
    HeapSort(arr,n);//Heap sort only works for the arrays that represent a Heap
    //printing
    for (int i = 1; i<=n; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}