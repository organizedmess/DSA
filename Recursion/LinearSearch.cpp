#include<iostream>
using namespace std;

int linear(int *arr,int key,int size){
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
     
    else{
        return linear(arr+1,key,size-1);
    }   

}
int main(){
    system("cls");
    int array[]={3,4,5,6,7,8,9};
    cout<<linear(array,4,7);
    return 0;
}