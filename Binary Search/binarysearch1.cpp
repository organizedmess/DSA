#include<iostream>
using namespace std;

int binary(int array[],int keey,int size)
{
    int start=0;
    int end= size-1;

    int mid = start + (end - start)/2;

    while(start<=end)
    {
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

int binary2(int *arr,int start,int end,int key){
    int mid = start +(end - start)/2;
    
    if(key==arr[mid]){
        return mid;
    }
    else if(start>=end){
        return -1;
    }
    else if(key<arr[mid]){
        return binary2(arr,start,mid-1,key);
    }
    else if(key>arr[mid]){
        return binary2(arr,mid+1,end,key);
    }

}

int main(){
    system("cls");
    int even[6]={1,3,5,7,9,11};
    int odd[7]={2,4,6,8,10,11,13};
    int key=7;
    // int index = binary(odd,key,7);
    int index = binary2(even,0,5,key);
    cout<<"Index of "<<key<<" is :"<<index;

}