#include<iostream>
using namespace std;

int sum(int arr[],int n){
        int s =0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return s;
}
int main(){
    system("cls");
    int n;
    cin>>n;
    
    int* arr = new int[n];//arr is the pointer that can access the array which has been created in Heap memory. 
    
    for (int i = 0; i < n; i++)
    {
        cout<<i<<"th element:"<<endl;
        cin>>arr[i];
    }
    cout<<sum(arr,n);
    
    return 0;
}