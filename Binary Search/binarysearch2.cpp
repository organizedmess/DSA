//First and last element in a sorted array

#include<iostream>
using namespace std;

int firstOcc(int arr[],int k,int size){
    int e=size-1;
    int s=0;
    int m = s + (e-s)/2;
    int answer;
    while(s<=e){ 
    if(arr[m]==k){
            answer = m;
            e = m-1;
        }
    else if(arr[m]>k){
            e = m-1;
        }
    else if(arr[m]<k){
            s = m+1;
        }
    m = s + (e-s)/2;
    }   
    return answer;
}
int firstOcc2(int *arr,int start,int end, int key,int answer){

    int mid = start + (end - start)/2;
    if(arr[mid]==key){
        answer = mid;
        return firstOcc2(arr,start,mid-1,key,answer);
    }
    else if(start>=end){//BASE CASE
        return answer;
    }
    else if (key>arr[mid]){
        return firstOcc2(arr,mid+1,end,key,answer);
    }
    else if (key<arr[mid]){
        return firstOcc2(arr,start,mid-1,key,answer);
    }
}

int lastOcc2(int *arr,int start,int end,int key,int answer){
    int mid = start + (end - start)/2;
    if(arr[mid]==key){
        answer = mid;
        return lastOcc2(arr,mid+1,end,key,answer);
    }
    else if (start>=end){//BASE CASE
        return answer;
    }
    else if (key>arr[mid]){
        return lastOcc2(arr,mid+1,end,key,answer);
    }
    else if (key<arr[mid]){
        return lastOcc2(arr,start,mid-1,key,answer);
    }    
}

int lastOcc(int arr[],int k,int size){
    int answer2;
    int s=0;
    int e=size-1;
    int m = s+(e-s)/2;
    while(s<=e){
    if(arr[m]==k){
        answer2 = m;
        s = m+1;
    }
    else if(arr[m]>k){
        e = m-1;
    }
    else if(arr[m]<k){
        s = m+1;
    }
    m = s + (e-s)/2;
    }
    return answer2;
}


int main(){
    system("cls");
    int even[6]={1,3,10,10,10,11};
    int odd[7]={2,2,8,10,10,13};
    int key=10;
    int index1 = firstOcc(even,key,6);
    int Inddex1 = firstOcc2(even,0,5,key,-1);
    int index2 = lastOcc(even,key,6);
    int inddex2 = lastOcc2(even,0,6,key,-1);
 
    cout <<"First Occurance :"<<index1<<endl;
    cout <<"First Occurance :"<<Inddex1<<endl;
    cout <<"Last Occurance :"<<index2<<endl;
    cout <<"Last Occurance :"<<inddex2<<endl;
    
}