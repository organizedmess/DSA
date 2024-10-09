#include<iostream>
using namespace std;



int func(int arr[],int size){

int s=0;
int e=size-1;
int mid= s+(e-s)/2;

while(s<e){
    
    if (arr[mid]<arr[mid+1]){
        s= mid+1;
    }  
    else{
        e= mid;
    }   
    
    mid= s+(e-s)/2;
}   
    return arr[e];
}


int func2(int *arr,int start,int end,int peak){
    int mid = start + (end - start)/2;
    
    if(start>=end){
        return arr[peak];//base case 
    }
    else if (arr[mid]<arr[mid+1]){
        return func2(arr,mid+1,end,peak);
    }
    else if(arr[mid]>arr[mid+1]){  
        peak = mid;
        return func2(arr,start,mid,peak);
    }
    
    
}
    


int main(){
    system("cls");
int array[7]={2,3,5,4,2,1,0};
int peak= func(array,7);
int peak2= func2(array,0,6,-1);

cout<<"Peak element is "<<peak<<endl;
cout<<"Peak element is "<<peak2<<endl;

}