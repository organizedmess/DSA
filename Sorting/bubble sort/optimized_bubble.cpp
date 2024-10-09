#include<iostream>
using namespace std;

void bubble(int *ptr,int n){
    for(int i=0; i<n-1; i++){
            bool swapped = false;
            for (int j = 0; j < n-i ; j++){
                   if (ptr[j]>ptr[j+1]){ 
                            swap(ptr[j],ptr[j+1]);
                            swapped = true;
            }}
            

            // OPTIMIZATION ↓(alt + 25)
        if(swapped == false)
            break;        
    }
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