#include<iostream>
using namespace std;


int func(int arr[],int size){
int s= 0;
int e= size-1;
int mid= s+(e-s)/2;

while(s<e){
if(arr[mid]>=arr[0]){// checking if its sorted

    s= mid+1;
}
else
{
    e= mid;
}
    mid= s+(e-s)/2;
}
    return arr[e];
}

int func2(int *arr,int start,int end){
    int mid = start + (end-start)/2;

    if (arr[mid]>arr[0]){
        start = mid + 1;
        return func2(arr,mid+1,end);
    }
    else if(start>=end){
        return arr[mid];
    }
    else{
        end = mid;
        return func2(arr,start,mid);
    }
}

int main(){

    system("cls");
    int arr[5]={7,9,3,1,2};
    int piv= func(arr,5);
    int piv2= func2(arr,0,4);
    cout<<"Pivot is "<<piv<<endl;
    cout<<"Pivot is "<<piv2<<endl;

}