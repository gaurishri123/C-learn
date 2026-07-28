//Problems on DLL 
//1. Deleting all the occurances of key in a DLL
//2. Find all the pair with given sum in DLL
//3. Removing all the duplicates in a DLL

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


//1. Deleting all the occurances of key in a DLL

Node* deleteKey(Node* head, int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                head=temp->next;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->back;
            if(prevNode!=NULL) prevNode->next=nextNode;
            if(nextNode!=NULL) nextNode->back=prevNode;
            delete(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }

    }
    return head;
}

//2.Find all the pairs with given sum in DLL
vector<int> sumPair(Node* head, int sum){
    vector<int> arr;
    Node* temp1=head;
    while(temp1!=NULL){
        Node* temp2=temp1->next;
        while(temp2!=NULL && temp1->data+temp2->data<=sum){
            if(temp1->data+temp2->data==sum){
                arr.push_back(temp1->data);
                arr.push_back(temp2->data);

            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

//Optimal Solution

Node* findTail(Node* head){
    Node* tail=head;
    while(tail!=NULL){
        tail=tail->next;
    }
    return tail;
}

vector<pair<int,int>> sumPair2(Node* head, int sum){
    vector<pair<int,int>> ans;
    Node* left=head;
    Node* right=findTail(head);
    while(left<right){
        if(left->data+right->data==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
        else if(left->data+right->data<sum){
            left=left->next;
        }
        else{
            right=right->back;
        }
    }
    return ans;
}

//3. Removing all the duplicates in a DLL

Node* removingDuplicates(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data){
            Node* duplicate=nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode!=NULL) nextNode->back=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,9};
    Node* head=convertArr2DLL(arr);
    head=deleteKey(head,10);
    print(head);
    return 0;
}