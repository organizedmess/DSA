#include <iostream> 
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->child;
    }
        cout<<endl;
}

Node* merge(Node* a,Node* b){
    Node* tempa=a;
    Node* tempb=b;
    Node* res=new Node(-1);
    Node* dummy=res;

    while(tempa!=NULL && tempb!=NULL)
    {
        if (tempa->data < tempb->data){
            dummy->child=tempa;
            dummy=dummy->child;
            tempa=tempa->child;
        }
        else{
            dummy->child=tempb;
            dummy=dummy->child;
            tempb=tempb->child;
        }
    }
    if (tempa!=NULL)
    {
        dummy->child=tempa;
    }
    else{
        dummy->child=tempb;
    }

    res=res->child;
    return res;

}

Node* Flatten(Node* head){

    Node* temp = head;
    if (head->next->next==NULL)
    {
        return merge(head, head->next);
    }

    temp->next=Flatten(temp->next);
    temp=merge(temp,temp->next);

    return temp; 
}

int main(){
    system("cls");
    Node* h1 = new Node(0);
    Node* h1c1 = new Node(3);
    Node* h1c2 = new Node(4);
    Node* h1c3 = new Node(5);
    Node* h2 = new Node(4);
    Node* h2c1 = new Node(7);
    Node* h2c2 = new Node(10);
    Node* h3 = new Node(5);
    Node* h3c1 = new Node(8);

    h1->next = h2;
    h2->next = h3;
    h3->next = NULL;

    h1->child=h1c1;
    h1c1->child=h1c2;
    h1c2->child=h1c3;
    h1c3->child=NULL;

    h2->child=h2c1;
    h2c1->child=h2c2;
    h2c2->child=NULL;

    h3->child=h3c1;
    h3c1->child=NULL;

    Node* result=Flatten(h1);
    print(result);
    return 0;
}