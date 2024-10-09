#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> v)
{   int count=0;
    for(int i=1; i<=v.size();i++)
    {
        if (v[i-1]>v[i] )
        {   cout<<i<<endl;
            count++;
        }
        
    }
       if(v.back()>v[0])
        { count++;}

    cout<<count<<endl;
    if(count<=1){return true;}
    else{return false;}
}

int main()
{   
    system("cls");
    vector<int> v = {3,4,5,1,2};
    vector<int> v2 = {1,2,3,4};
    
    cout<<check(v2)<<endl;

    if(check(v2)==true)
        {cout<<"Was Sorted and Rotated";}
    else{
        cout<<"Wasn't Sorted and Rotated";
    }

}