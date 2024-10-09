#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

Node* rev(Node* &Head,int k){
    Node* curr= Head;//New Head every time.
    Node* prev=NULL;
    Node* forward=NULL;
    
    if(Head == NULL)//Base Case
    {   
        return NULL; //NULL because the last element is pointing to NULL.
    }
    
    int count=0;
    while (curr!=NULL && count<k)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
//'Previous' here is the first element of the group.
//while Head is now the last. 

    if (curr!=NULL)
    {
        Head->next=rev(curr,k);//This specific Head is now the last element of this specific group.
                                //While the final previous of the iteration is the first element of the group.
    }
    
    return prev;//last prev of that specific iteration becomes the first element of that recursive call. 
}              //so we want to connect the the first element of the next recursive call to the last element of this
              //this recursive call(HeaD).

int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(30);
    Node* fourthElement = new Node(40);
    Node* fifthElement = new Node(50);
    Node* sixthElement = new Node(60);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;

    Node* prev= NULL;
    Node* final = rev(Head,4);
    print(final);


    return 0;
}