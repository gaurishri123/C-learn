//Defining a self defined datatype
#include<bits/stdc++.h>
using namespace std;

struct Node{ //in place of struc we can also put class 
    public:  //class offers OOPs benefits whereas struct doesn't
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* y= new Node(arr[0], nullptr);
    cout<<y;

}