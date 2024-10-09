#include<iostream>
using namespace std;

void swapp(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

int partition(int *arr,int s,int e){
    
    int pivot = arr[s];
    int count=0;
        
    for(int i=0; i<e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivot_index = (s + count); //This is to make space on the left side for the smaller elements.
    
    
    swapp(arr[s],arr[pivot_index]); 
    
    while (s < pivot_index && e > pivot_index)
    {
        while(arr[s] <= pivot){
            s++;
        }
        while(arr[e] > pivot){
            e--;
        }

        if (s < pivot_index && e > pivot_index)
        {
            swapp(arr[s],arr[e]);    
        }
    }    
    return pivot_index;
}
    


void QuickSort(int* arr,int start,int end){
    if (start >= end){  //BASE CASE: meaning that the array has been reduced to length ONE.
        return ;
    }
    
    int partition_Index = partition(arr,start,end);

    QuickSort(arr,start,partition_Index-1); 
    QuickSort(arr,partition_Index+1,end); 

}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
}
int main(){
    system("cls");
    int array[]={4,3,7,2,1};
    QuickSort(array,0,4);
    print(array,5);
    return 0;
}