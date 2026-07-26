//Problems on Linked List
//1. Finding the middle node of a linked list
//2. Reversing a LL by traversal method and recursive method
//3. Finding a Loop in the LL
//4. Finding the starting point of loop if there is any
//5. Finding Length of a Loop in LL
//6. Finding if a LL is palindromic or not
//7. Odd and even Linked List
//8. Removing The Nth node from the end of the linked list
//9. Deleting the middle node of the linked list
//10. Merging two linked lists
//11.Sorting the Linked List
//12. Sorting a Linked List having zeroes and ones
//13. Finding the intersection point of a y Linked List
//14. Adding one to the digits of the Linked List
//15. Adding two number of a linked List

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
int lengthOfLoo2(Node* head){
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

//6. Finding if a LL is palindromic
bool palindrome(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()) return false;
        temp=temp->next;
        st.pop();

    }
    return true;
}

//Optimal Solution
//In finding the middle of LL we were looking for the second middle when lenght is even
//Therefore the condition was written as fast!=NULL for even
//Here we are looking for the first middle so the condition is fast->next->next!=NULL
//for odd, the condition remains same 
//Since the links are never changed, slow will always point to slow->next
//therefore second=newHead

bool palindrome2(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL2(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL){
        if(second->data!=first->data){
            reverseLL2(newHead);
            return false;
        }
        first=first->next;
        second=second->next;

    }
    reverseLL2(newHead);
    return true;
}

//7. Odd Even Problem
//Brute Force 

Node* oddEven(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    vector<int> lst;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        lst.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=NULL) lst.push_back(temp->data); //we might skip one odd index because of temp->next!=NULL condition

    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        lst.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=NULL) lst.push_back(temp->data);//same reason as above

    int i=0;
    temp=head;
    while(temp!=NULL){
        temp->data=lst[i];
        i++;
        temp=temp->next;
    }
    return head;
    
}

//Optimal Solution
Node* oddEven2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;
    //since even will always be ahead of odd, we write condition for only even
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

//8. Removing the Nth node from the end of the LL
//Brute force

Node* removeNth(Node* head, int n){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newHead=head->next;
        return newHead;
    }
    int res=cnt-n;
    temp=head;
    while(temp!=NULL){
        res--;
        if(res==0){
            break;
        }
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    free(deleteNode);
    return head;
}

//Optimal Solution

Node* removeNth2(Node* head, int n){
    Node* fast=head;
    Node* slow=head;
    for(int i=0; i<n; i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* deleteNode=slow->next;
    slow->next=slow->next->next;
    free(deleteNode);
    return head;
}

//9. Deleting thr middle node of a LL
//we need to try to reach the node before the middle node

Node* deletingMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int res=cnt/2;
    temp=head;
    while(temp!=NULL){
        res--;
        if(res==0){
            break;
        }
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    delete(deleteNode);
    return head;
}

//OPTIMAL SOLUTION

Node* deletingMiddle2(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* fast=head;
    Node* slow=head;
    fast=fast->next->next; //here we are skipping one slow step since we need to reach the node before the middle node
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* deleteNode=slow->next;
    slow->next=slow->next->next;
    delete(deleteNode);
    return head;
}

//10. Merging two sorted Linked Lists

Node* merge(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    vector<int> arr;
    while(temp1!=NULL){
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());
    Node* head=convertArr2LL(arr);
    return head;
}

//Optimal Approach

Node* merge2(Node* head1, Node* head2){
    Node* dummyNode=new Node(-1);
    Node* temp1=head1;
    Node* temp2=head2;
    Node* temp=dummyNode;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1){
        temp->next=temp1;
        
    }
    else{
        temp->next=temp2;
    }
    return dummyNode->next;
}

//Finding the middle but the middle points to the first middle in even Length

Node* middleNode3(Node* head){
    Node* slow=head;
    Node* fast=head->next; //since we want the first middle 
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//11. Sorting the Linked List
Node* sorting(Node* head){
    Node* temp=head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}

//Optimal Solution

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* middle=middleNode3(head);
    Node* right=middle->next;
    middle->next=nullptr;
    Node* left=head;

    left=mergeSort(left);
    right=mergeSort(right);

    return merge2(left,right);
}

//12. Sorting a Linked List Having zeroes and ones

Node* sort2(Node* head){
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            cnt0++;
        }
        else if(temp->data==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}

//Optimal Solution

Node* sort2a(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    //Checking if there are ones or not else pointing to twos
    zero->next=(oneHead->next)? oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=nullptr;
    Node* newHead=zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return newHead;
}

//13. Finding the first intersection node of Y linked List

Node* yLinkedList(Node* head1, Node* head2){
    Node* temp1=head1;
    map<Node*, int> mpp;
    while(temp1!=NULL){
        mpp[temp1]=1;
        temp1=temp1->next;
    }
    temp1=head2;
    while(temp1!=NULL){
        if(mpp.find(temp1)!=mpp.end()){
            return temp1;
        }
        temp1=temp1->next;
    }
    return nullptr;
}

//Better approach

Node* collisionPoint(Node* t1, Node* t2, int d){
    while(d){
        d--;
        t2=t2->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}

Node* yLinkedList2(Node* head1, Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    int N1=0;
    int N2=0;
    while(t1!=NULL){
        N1++;
        t1=t1->next;
    }
    while(t2!=NULL){
        N2++;
        t2=t2->next;
    }
    if(N2>N2){
        return collisionPoint(head1,head2,N2-N1);//considering head1 to be small
    }
    else{
        return collisionPoint(head2,head1,N1-N2);//considering head2 to be small
    }
}

//Optimal Approach

Node* yLinkedList3(Node* head1, Node* head2){
    if(head1==NULL || head2==NULL){
        return NULL;
    }
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2) return t1;
        if(t1==NULL){
            t1=head2;
        }
        if(t2==NULL){
            t2=head1; 
        }
    }
    return t1;
}

//14. Adding one to the digits of the Linked List

//Iterative Solution
//Pros-no Space
//Cons=TC=0(3N) with tampering of data

Node* addingOne(Node* head){
    Node* temp=head;
    int carry=1;
    head=reverseLL2(head);
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            carry=1;
            temp->data=0;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newHead= new Node(1);
        head==reverseLL2(head);
        newHead->next=head;
        return newHead;
    }
    head=reverseLL2(head);
    return head;

}

//Recursive Solution
//Pros-No tampering of data, addition done in place and less time taked
//Cons-Extra Recursive Stack Space

int helper(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}

Node* addingOne2(Node* head){
    int carry=helper(head);
    if(carry==1){
        Node* newHead= new Node(1);
        newHead->next=head;
        return newHead;
    }
    return head;
}

//15. Adding Two numbers of a linked list

Node* addingTwo(Node* head1, Node* head2){
    int carry=0;
    Node* l1=head1;
    Node* l2=head2;
    Node* dummyNode=new Node(0);
    Node* temp=dummyNode;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=node;
    }
    return dummyNode->next;    
}

int main(){
    vector<int> arr={9,9,9,9};
    Node* head=convertArr2LL(arr);
    head=addingOne2(head);
    print(head);
}

