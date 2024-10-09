#include<iostream>
using namespace std;

void moveZero(int *arr,int n){
//we are simply shifting all non-zero vales to left
    int nonzero=0;
for (int i = 0; i < n; i++)
{
    if (arr[i]!= 0)
    {
        swap(arr[i],arr[nonzero]);
        nonzero++;
    }
    
}
}

void printarray(int arr[],int n){
     for(int i = 0 ; i < n ; i++){  
        cout<<arr[i]<<" ";
   }
        cout<<endl;  
}

int main(){  
    system("cls");
    int array[]={2,0,1,0,12};
    moveZero(array,5);
    printarray(array,5);


}