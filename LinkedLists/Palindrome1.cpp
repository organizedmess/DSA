#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data ;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

vector<int> createArray(Node* Head){
    vector<int> vec;

    while (Head!=NULL)
    {
        vec.push_back(Head->data);
        Head = Head->next;
    }
    return vec;
}

bool checkPalindrome(Node* &Head){
    vector<int> vec = createArray(Head);

    int start=0;
    int end= vec.size()-1;
    while(start<=end){
        if(vec[start]!=vec[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(30);
    Node* fourthElement = new Node(20);
    Node* fifthElement = new Node(10);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = NULL;

    cout<<checkPalindrome(Head);

    return 0;
}