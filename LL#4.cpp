//Deletion of head
//Deletion of tail
//Removes any K element
//Remove element
//Insert Head
//Insert Tail

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}


//removes head

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp; //free up the memory space of the previous head
    return head;
    
}

//removes tail

Node* removeTail(Node* head){
    //if LL is empty or the LL has only one element
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head; //stores head 
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next; //free up the memory space of previous tail
    temp->next=nullptr; //points the current tail(tail after deletion of previous tail) to the NULL so it actually becomes the tail
    return head;
}

//removes any K positon

Node* removeK(Node* head, int k){
    //if LL is empty
    if(head==NULL) return head;

    //if K is first element
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }

    //if K is any other element or the tail
    int cnt=0;
    Node* prev=NULL;
    Node* temp=head;
    //while temp is a element
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp); //removing the Kth element
            break;
        }
        prev=temp;
        temp=temp->next; //moving temp to next 
    }
    return head;
}

//Remove the stated element 
Node* removeElement(Node* head, int el){
    //if LL is empty
    if(head==NULL) return head;

    //if it is first element
    if(head->data==el){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }

    //if it is any other element 
    Node* prev=NULL;
    Node* temp=head;
    //while temp is a element
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=prev->next->next;
            free(temp); //removing the Kth element
            break;
        }
        prev=temp;
        temp=temp->next; //moving temp to next 
    }
    return head;
}

//Insertion of new element

Node* insertHead(Node* head, int val){
    return new Node(val,head); // the confusion can be in the main function since the function argument is reverse of the argument inside the function
}

Node* insertTail(Node* head, int val){
    if(head==NULL) return new Node(val);
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next; //loop stops when next of temp points to null
                         //Therefore the final temp is the last element of LL
    }
    Node* newNode=new Node(val);
    temp->next=newNode; //The next of last element will be pointing to the new element
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2LL(arr);
    head=insertTail(head,100); 
    print(head);
}
