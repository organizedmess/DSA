#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0] = -1;//first index is considered invalid 
        size = 0;
    }

    void swapp(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent_index = index/2;//to find the parent of index

            if (arr[parent_index] < arr[index])//max_heap 
            {
                swapp(arr[parent_index],arr[index]);
                index = parent_index ;//this line here is important because it helps us compare 
                //the new parent with its parent and if the swap occurs then again with the grandparent
            }
            else
            {
                return ;
            }
        }
    }
    
    void deleteFromHeap(){
        if (size == 0)
            return ;
        
        int index = 1;
        swapp(arr[size],arr[1]);
        //swapped the first node and the last node
        arr[size--];//deleted the former top node

        while (index < size)
        {   
            pair<int,int> child_index = make_pair(2*index,(2*index)+1);
            
            int largetChildIndex = ( (arr[child_index.first] > arr[child_index.second] ? child_index.first : child_index.second) );
            int SmallerChildIndex = ( (arr[child_index.first] < arr[child_index.second] ? child_index.first : child_index.second) );

            if(arr[index] < arr[largetChildIndex] && largetChildIndex < size){
                swapp(arr[index],arr[largetChildIndex]);
                
                index = largetChildIndex;//this is the new place of the swapped last node            
            }
            else if(arr[index] < arr[SmallerChildIndex] && SmallerChildIndex < size){
                swapp(arr[index],arr[SmallerChildIndex]);
                
                index = SmallerChildIndex;//this is the new place of the swapped last node            
            }
            else
            {
                return;
            }
        }
    }
    
    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }   
        cout<<endl;
    }

};

int main(){ 
    system("cls");
    Heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    

    return 0;
}