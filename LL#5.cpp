//Introduction to a doubly linked list
//Conversion of array to DLL
//Deletion of Node (deletion of head,tail,Kth node,any given node)
//Insertion of Node (before head, before tail, before a Kth node, before a given node)

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

//CONVERTION OF ARRAY TO DLL

Node* convertArr2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1; i<arr.size(); i++){
        Node* temp=new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//DELETING THE HEAD

Node* removeHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    head=head->next;
    head->back=NULL;
    prev->next=NULL;
    delete prev;
    return head;
}

//DELETING THE TAIL
Node* removeTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    prev->next=NULL;
    temp->back=NULL;
    delete temp;
    return head;
}

//DELETING THE Kth ELEMENT IN A DLL

Node* removeKthElement(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
    }

    else if(prev==NULL){
        return removeHead(head);
    }

    else if(front==NULL){
        return removeTail(head);
    }

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;

}

//REMOVING THE GIVEN NODE
//This question will never give head as the node

void removeNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;

    }

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
}

//INSERTING A NODE BEFORE THE HEAD

Node* insertBeforeHead(Node* head, int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

//INSERTING NODE AFTER HEAD

Node* insertAfterHead(Node* head, int val){
    Node* front=head->next;
    Node* newHead= new Node(val, front, head);
    if(front!=nullptr){
        front->back=newHead;
    }
    head->next=newHead;
    return head;
}

//INSERTING A NODE AFTER THE TAIL

Node* insertAfterTail(Node* head, int val){
    if(head==nullptr){
        return new Node(val,nullptr,nullptr);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newTail= new Node(val,nullptr,temp);
    temp->next=newTail;
    return head;
}

//INSERTING A NODE BEFORE TAIL

Node* insertBeforeTail(Node* head, int val){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newTail= new Node(val, temp,prev);
    prev->next=newTail;
    temp->back=newTail;
    return head;

}

//INSERT BEFORE Kth ELEMENT

Node* insertBeforeKth(Node* head, int k, int val){
    if(k==1){
        return insertBeforeHead(head, val);
        
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode= new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}

//INSERT BEFORE A GIVEN NODE

void insertBeforeNode(Node* node, int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2DLL(arr);
    head=insertBeforeKth(head,3,10);
    print(head);
    return 0;
}