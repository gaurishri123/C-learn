//Problems on Linked List
//1. Finding the middle node of a linked list
//2. Reversing a LL by traversal method and recursive method
//3. Finding a Loop in the LL
//4. Finding the starting point of loop if there is any
//5. Finding Length of a Loop in LL

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

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

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

//1.finding the middle Node(in case of even, we take the second node which comes in the middle)
//Brute Force

Node* middleNode(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int middle=(cnt/2)+1;
    temp=head;
    while(temp!=NULL){
        middle=middle-1;
        if(middle==0){
            break;
        }
        temp=temp->next;
    }
    return temp;

}

//Optimal Solution
Node* middleNode2(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//2.Reversing A LL (traversal)

Node* reverseLL(Node* head){
    Node* temp=head;
    stack<int> st;  //stack is a data structure which follows first in first out rule
    while(temp!=NULL){      //filling every node in stack
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){   //replacing the data of original LL to stack data
        temp->data=st.top();
        st.pop();  //simultaneously deleting the stack data
        temp=temp->next;
    }
    return head;

}

//Optimal Solution 
//Stack data structure takes 0(n) space complexity
//Playing along with the links in this approach

Node* reverseLL2(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

//Recursive solution of Reversing the LL
//TC=0(N) SC=0(N) since recursion has a stack space 

Node* reverseLL3(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead= reverseLL3(head->next);
    Node* front= head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

//3. Finding a Loop in the LL
//Brute Force

bool findingLoop(Node* head){
    map<Node*, int> mpp;
    Node* temp=head;
    while(temp!=NULL){
        if(mpp.find(temp)!= mpp.end()) return true;
        mpp[temp]++;
        temp=temp->next;
    }
    return false;
}

//Optimal Solution

bool findingLoop2(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==head){
            return true;
        }
    }
    return false;
}

//4.Finding the Starting point of a Loop
Node* findingStart(Node* head){
    map<Node*, int> mpp;
    Node* temp=head;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}

//Optimal Solution
Node* findingStart2(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

//5. Finding Length of a Loop 

int lengthOfLoop(Node* head){
    map<Node*, int> mpp;
    Node* temp=head;
    int timer=1;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            int value=mpp[temp];
            return timer-value;
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
}

//Optimal Solution
int lengthOfLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=1;
            fast=fast->next;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2LL(arr);
    Node* ans=findingStart(head);
    cout<<ans;
    return 0;
}