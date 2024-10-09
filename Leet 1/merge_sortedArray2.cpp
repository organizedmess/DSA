#include<iostream>
using namespace std;

void merge(int *arr1,int n,int *arr2,int m){
    int k = n + m - 1;
    int i = n-1 , j = m-1;

    while(i>=0 && j>=0)
    {

        if(arr1[i]>arr2[j]){

            arr1[k] = arr1[i];
            i--;
            k--;

        }
        else{

            arr1[k] = arr2[j];
            k--;
            j--;

        }
        
    }

    while (i>=0)
        arr1[k--]=arr1[i--];

    while (j>=0)
        arr1[k--]=arr2[j--];
    
}

void printarray(int arr[],int n){
     for(int i = 0 ; i < n ; i++){  
        cout<<arr[i]<<" ";
   }
        cout<<endl;  
}

int main(){

system("cls");
int arr1[]={1,2,3,0,0,0};//0 represents empty spaces
int arr2[]={2,5,6};

merge(arr1,3,arr2,3);
printarray(arr1,6);

}