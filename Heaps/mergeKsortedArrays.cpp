#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    int index;
    int arrPos;
    Node(int d,int i,int a){
        this->data = d;
        this->index = i;//index of the element 
        this->arrPos = a;//array to which it belongs 
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){//we are not pushing 'nodes' not 'int' into queue,
        bool compare = a->data > b->data;//hence we need this comparator function to do the comparasion on the basis of node->data
        return compare; //like min heap
    }
};

vector<int> merge(vector<vector<int> >vec,int k){

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < k; i++)//pushing the first element of all the arrays as nodes 
    {                         //into the heap
        Node* temp = new Node(vec[i][0],0,i);// "i" refers to array position
        pq.push(temp);
    }   
    
    vector<int> res;

    while (!pq.empty())
    {
        Node* first = pq.top();
        int data = first->data;
        int arrposition = first->arrPos;//which array had the smallest element, to increase its index
        int element_index = first->index;
        res.push_back(data);
        pq.pop();

        //
        if ( element_index+1 < vec[arrposition].size())//please dont push garbage value inside the min heap :)
        {    
            Node* temp = new Node(vec[arrposition][element_index+1],element_index+1,arrposition);//pushing the next element of the array from which the 'data' belonged
            pq.push(temp);                                                                      
        }
    }

    return res;
}

int main(){
    system("cls");
    vector<vector<int>> v = 
    {
        {3,5,8},{1,4},{2},{6,11},{5,8}
    };

    vector<int> answer = merge(v,v.size());
    int i = 0;
    while (i < answer.size())
    {
        cout<<answer[i]<<" ";
        i++;
    }

    return 0;
}