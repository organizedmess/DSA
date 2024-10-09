#include<iostream>
using namespace std;


void mergeSort(int arr1[],int n,int arr2[], int m,int *arr3){

int i = 0, j=0;
int k = 0 ;
while (i<n && j<m)
{
    if(arr1[i]<arr2[j]){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    else{
        arr3[k] = arr2[j];
        k++;
        j++;    
    }
}

while (i<n)
{
    arr3[k++]=arr1[i++];
}
while (j<m)
{
    arr3[k++]=arr2[j++]; 
}

}

void printarray(int arr[],int n){
     for(int i = 0 ; i < n ; i++){  
        cout<<arr[i]<<" ";
   }
        cout<<endl;  
}

int main(){
    system("cls");

    int arr1[4]={2,4,6,8};
    int arr2[3]={1,3,5};
    int arr3[7]={};
    
   
    mergeSort(arr1,4,arr2,4,arr3);
    printarray(arr3,8);

}