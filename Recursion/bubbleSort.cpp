#include<iostream>
using namespace std;

void swapp(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble(int *arr,int n){
    if (n<=1)
    {
        return ; //BASE CASE
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>arr[i+1])
        {
            swapp(arr[i],arr[i+1]);
        }
        
    }
    bubble(arr,--n);
}


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    system("cls");
    int array[]={3,5,1,4,7};

    print(array,5);
    bubble(array,5);
    print(array,5);

}