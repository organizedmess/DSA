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
    int array[7]={1,2,3,3,3,3,5};

    int occurence = lastOcc(array,3,7) - firstOcc(array,3,7) + 1;
    cout<<"It is occuring "<<occurence<<" times."<<endl;

    
    }