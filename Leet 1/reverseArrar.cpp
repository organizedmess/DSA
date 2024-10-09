#include<iostream>
using namespace std;

void rev(int *a,int n){
   int s=0,e=n-1;
   while (s<=e)
   {
    swap(a[s],a[e]);
    s++;
    e--;
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
 int array[]={3,4,1,7,2};
        printarray(array,5);
        rev(array,5);
        printarray(array,5);
}