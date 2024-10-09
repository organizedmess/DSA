#include<iostream>
using namespace std;


void bubble(int *arr,int n){

        for(int i = 0; i<n-1;i++){
            for(int j = 0;j<n-i;j++){
                    if(arr[j]>arr[j+1])
                        swap(arr[j],arr[j+1]);
            }
        }
}
void printarray(int arr[],int n){

        for (int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
}



int main(){
    system("cls");
    int array[]={3,5,1,4,7};

    printarray(array,5);
    bubble(array,5);
    printarray(array,5);

}