// Step 1: Find pivot.
// Step 2: Check if your element is larger or smaller than the pivot.


#include<iostream>
using namespace std;

int pivot(int arr[],int size){//FIND THE PIVOT

int s= 0;
int e= size-1;
int mid= s + (e-s)/2;

while(s<e){

if(arr[mid]>=arr[0]){
    s = mid+1;
}
else{
    e= mid;
}
mid = s+(e-s)/2;
}
    return e;//INDEX OF THE PIVOT.
}

int binary(int array[],int keey,int start ,int end){
    
    int mid = start + (end - start)/2;

    while(start<=end){

        if(array[mid]==keey){
            return mid;
        }
        if(array[mid]>keey){
            end = mid - 1;
        }
        if(array[mid]<keey){
            start = mid + 1;
        }

        mid = start + (end - start)/2;//updating mid
        }
            return -1;
    }

int pivot2(int *arr,int start,int end){
    int mid = start + (end - start)/2;

    if(arr[mid]>arr[0]){
        //start = mid + 1
        return pivot2(arr,mid+1,end);
    }
    else if(start>=end){
        return mid;
    }
    else if(arr[mid]<arr[0]){
        //end = mid
        return pivot2(arr,start,mid);
    }    
}

int main(){
    system("cls");
int arr[]={3,7,9,11,1,2};
int key=9;
int piv = pivot(arr,6);
cout<<"Index of the pivot is "<<piv<<endl;
int piv2 =pivot2(arr,0,5);
cout<<"Index of the pivot "<<piv2<<endl;

// Checking in which Array would the pivot lie. 

if(arr[0]<key){//If its belongs to the first array.
    int search= binary(arr,key,0,piv-1);
        cout<<"The elemeny is at index "<<search<<endl;
}
else{//Or the second.
    int search= binary(arr,key,piv,6);
        cout<<"The elemeny is at index "<<search<<endl;
    }

}