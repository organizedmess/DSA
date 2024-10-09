#include<iostream>
using namespace std;


int insertion(int *arr,int n){
   for(int i = 0; i<n; i++){
        for (int j = i; j > 0; j--)
        {
            if (arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else{
                break;
            }    
        }
        
   }
}
void printarray(int arr[],int n){
    
    for(int i=0 ; i < n ; i++){  
        cout<<arr[i]<<" ";
   }
   cout<<endl;  
}

int main(){
        system("cls");
        int array[]={3,4,1,7,2};
        printarray(array,5);
        insertion(array,5);
        printarray(array,5);
}