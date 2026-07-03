//Length of a Linked List
#include<bits/stdc++.h>
using namespace std;

struct Node{ //in place of struc we can also put class 
    public:  //class offers OOPs benefits whereas struct doesn't
    int data;
    Node* next;
    
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
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}

//length of LL 

int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        //cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2LL(arr);
    cout<<lengthOfLL(head);
}