#include<iostream>
using namespace std;


bool possible(int arr[],int n,int m,int mid){
    int sum = 0;
    int paintercount = 1;
    for(int i =0;i<n;i++){
        if(sum + arr[i]<=mid){
            sum =+arr[i];
        }
        else{
            paintercount++;
            if(paintercount>m || arr[i]>mid){
                return false;
            }
            sum = arr[i];
        }
    }
    if(paintercount>m){
            return false;
    }
            return true ;
}

int allocation(int arr[],int n ,int m){

int start = 0;
int end = n -1;
int sum =0;
            for(int i=0;i<n;i++){
                    sum +=arr[i] ;
                }
int ans =-1;
    end = sum ; 
int mid = start +(end - start)/2;

        while(start<=end){
    if(possible(arr,n,m,mid)){
                ans = mid ;
                end = mid -1;
       }
    else {
        start = mid + 1;
    }
    mid = start +(end -start)/2;
}
    return ans;
}

int main(){
    system("cls");
    // m = no. of students 
int array[5]={1,2,2,3,1};
cout<<allocation(array,5,3);

}