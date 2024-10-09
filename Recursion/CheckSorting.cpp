#include<iostream>
using namespace std;


bool check(int *arr,int size){
    if(size == 1){
        return true;//This is the only condition that validates that array is sorted.
    }
    else if(arr[0] > arr[1]){
        return false;
    }
    else{
        return check(arr+1,size-1);
    }
}


int main(){
    system("cls");
    int array[]={3,4,5,6,7,8,9};
    cout<<check(array,7);
    return 0;    
}