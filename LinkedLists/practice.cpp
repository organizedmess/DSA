#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int d){
        this->val=d;
        this->next = NULL;
    }
};

void print(ListNode* &Head){
    ListNode* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

ListNode* reverseNode(ListNode* &Head,int pos){
    ListNode* prev=NULL;
    ListNode* curr=Head;
    int i =1;

    while (curr != NULL && i<=pos-1)
    {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    Head = prev;
    return Head;
}

bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int i = 0;
        while(temp!=NULL){
            temp=temp->next;            
            i++;
        }

        
        ListNode * forr= head;
        for(int j=0;j<i/2;j++)
        {
            forr=forr->next;
        }
        int num =i/2;

        ListNode * prev= head;
        while(forr != NULL)
            {   
                for(int k=0;k<num;k++){
                    prev = prev->next;
                }
                if(prev->val == forr->val){
                    continue;
                }
                else{
                    return false;
                }
                forr = forr->next;
                num--;
            }

            return true;
}

bool palin(ListNode* head){
    int i = 1;
    ListNode* temp = head;
    ListNode* pointerr = head; 
    
    while (temp != NULL)
    {
        temp=temp->next;
        i++;
    }
    int j=1;
    while (j<=i/2)
    {
        pointerr=pointerr->next;
        j++;
    }
    
    ListNode* rev = reverseNode(head,i/2);
    
    print(rev);

    while(pointerr != NULL)
    {
        if (rev->next != pointerr->next)
        {
            return false;
        }
        else{
            continue;
        }
        rev=rev->next;
        pointerr=pointerr->next;
        
    }
    
}


int main(){
    system("cls");
    ListNode* Head = new ListNode(10);
    ListNode* secElement = new ListNode(20);
    ListNode* thirdElement = new ListNode(20);
    ListNode* fourthElement = new ListNode(40);
    // ListNode* fifthElement = new ListNode(40);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = NULL;
    // fifthElement->next = NULL;

    cout<<palin(Head);
    return 0;
}

