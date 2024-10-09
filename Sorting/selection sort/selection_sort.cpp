#include<iostream>
using namespace std;


void printarray(int arr[],int n){
    
    for(int i=0 ; i < n ; i++){  
        cout<<arr[i]<<" ";
   }
   cout<<endl;  
}

void selectionsort(int *arr,int n){
    int min,temp;
    for(int i ; i<n-1 ; i++){       // j < n-1 becoz the array will already be sorted by that point.
             min = i ;

            for( int j = i+1 ; j<n ; j++ ){ // j < n becoz we want to consider the last postion element as a contender as well.

                    if(arr[j]<arr[min]){
                        min = j ;
                        // cout<<arr[min];
                    }
        }
                // swap(&arr[min],&arr[i]);
                 temp = arr[i];
                arr[i] = arr[min];
                arr[min]=temp;
        }
}
            
    

 
int main(){
        system("cls");
        int array[]={3,4,1,7,2};
        printarray(array,5);
        selectionsort(array,5);
        printarray(array,5);

        return 0;

}