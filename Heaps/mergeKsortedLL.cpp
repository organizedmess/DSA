#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node<int>{
    int data;
    Node<int>* next = NULL;
};

class compare{
    public:
    int data;
    bool operator()( Node<int>* a,Node<int>* b){
        bool compareThis = a->data > b->data;  
        return compareThis;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> pq;
    
    if (listArray.size() == 0)
        return NULL;//if there no lists to compare
    
    
    for(int i=0;i<listArray.size();i++)
    {
      if(lists[i] != NULL)
      {//head of all the lists 
        pq.push(lists[i]);
      }
    }

    if (pq.size() == 0)
    {//if all the head are null
        return NULL;
    }
    
    Node<int>* Head = NULL;
    Node<int>* Tail = NULL;
    
    while(!pq.empty())
    {   
        Node<int>* topElement = pq.top();
        pq.pop();

        if(topElement->next)
            pq.push(topElement->next);//insertion in minHeap
        
        if(Head == NULL)//will only run once,in the start
        {//answer Linked list is empty
            Head = topElement;
            Tail = topElement;
        }
        else
        {//insertion at Linked list
            Tail->next = topElement;
            Tail = topElement;
        }
    }
    return Head;
}

int main(){
    system("cls");
    
    return 0;
}