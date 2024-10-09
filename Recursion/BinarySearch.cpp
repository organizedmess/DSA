#include<iostream>
using namespace std;

int binary(int *arr,int start,int end,int key){
    int mid = start + (end - start)/2;

    if(key == arr[mid]){
        return mid ;  //base case for key present    
    } 
    else if(start>=end){
        return -1;  //base case for key not present 
    }
    else if(key<arr[mid]){
        return binary(arr, start, mid-1, key);
    }
    else{
        return binary(arr, mid+1, end, key);
    }
}

int main(){
    system("cls");
    int array[]={3,4,5,6,7,8,9};
    cout<<binary(array,0,6,8);
    return 0;
}