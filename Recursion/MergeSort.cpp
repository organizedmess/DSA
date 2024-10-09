#include<iostream>
using namespace std;


void merge(int *arr,int start,int end){
    int mid = start + (end - start)/2;
    
    // creating two arrays based on the mid
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //Copying the values 
    int mainIndexArray = start;
    //first array
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndexArray++];
    }
    //second array 
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndexArray++]; 
    }

    //MERGE THE ARRAYS

    int index1 = 0;//Through this we will  travese through array1
    int index2 = 0;//Through this we will traverse through array2
    
    mainIndexArray = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2]){
            arr[mainIndexArray++] = first[index1++];
        }

        else{
            arr[mainIndexArray++] = second[index2++];
        }
    }
    // second array ran out elements but first still got some then just copy the first array into the main array
        while (index1 < len1)
        {
            arr[mainIndexArray++] = first[index1++];        
        }
    // first array ran out of elements but second still got some then simply copy the remaining second array into the main array
        while (index2 < len2)
        {
            arr[mainIndexArray++] = second[index2++];
        }

}

void mergeSort(int *arr,int start,int end){
    int mid = start + (end - start)/2;
    
    if (start >= end)//BASE CASE
    {   return ; }
        
    

    // recursion
    mergeSort(arr,start,mid);//sort the left part 
    mergeSort(arr,mid+1,end);//sort the right part

    //merge
    merge(arr,start,end);
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    system("cls");
    int array[] = {4,5,2,3,1};
    print(array,5);
    mergeSort(array,0,4);
    print(array,5);
    return 0;
}