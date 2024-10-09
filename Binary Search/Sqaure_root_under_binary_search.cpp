#include<iostream>
using namespace std;

int root(int n){

long long int mid ;//so that value doesn't exceed the max integer limit in mid*mid
int start=0 , end = n , ans;
mid = start + (end - start)/2;

while(start<=end)
{
if(mid*mid==n){
    ans = mid;
    return mid;
}
else if(mid*mid>n){
    end = mid-1;
}
else if(mid*mid<n){
    ans = mid;//to avoid garbage value if there is no perfect square root
    start = mid+1; 
}
mid = start + (end - start)/2;
}
    return ans;
}



double morePrecision(int n,int prec,int temp){


double fact = 1;
double ans = temp;
    for(int i =0;i<prec; i++)
    {
        fact=fact/10;
        for(double j=ans; j*j<n; j=j+fact)
        {
            ans=j;
        }
    }   
        return ans;
}
    
int main(){
system("cls");
cout<<root(6.25)<<endl;
cout<<morePrecision(6.25,1,2);

}