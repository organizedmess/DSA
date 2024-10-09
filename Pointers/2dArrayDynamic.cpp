#include<iostream>
using namespace std;


int main(){
    system("cls");

    int c;
    cin>>c;
    int r;
    cin>>r;
    // creating the array 
    int **arr = new int*[r];//an array 'arr' of type 'pointer'.

    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[3];//allocating memory for each pointer that is about to become an array.
    }
     

    //taking the input
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
    }

    // printing the output 
    cout<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    delete []arr;
    
    return 0;
}
        
    
    