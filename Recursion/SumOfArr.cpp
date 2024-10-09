#include<iostream>
using namespace std;

int sum1(int *arr,int n,int last_index){
    if(n == (last_index-1))
    {    
        return arr[(last_index-1)];
    }
    else
    {
        return (arr[n] + sum1(arr,++n,last_index));
    }
}
int sum2(int *arr,int size){
    if(size == 1){
        return arr[0];
    }
    // else if(size == 0){
    //     return 0;
    // }
    else{
        return (arr[0] + sum2(arr+1,size-1));
    }
}
int main(){
    system("cls");
    int array[]={4,7,2,3,10};
    cout<<sum1(array,0,5);
    cout<<endl;
    cout<<sum2(array,5);
    return 0;
}