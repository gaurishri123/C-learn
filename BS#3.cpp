//First and last occurance of any element x
#include<bits/stdc++.h>
using namespace std;


//BIG0(N) TIME COMPLEXITY SOLUTION

vector<int> firstLast(vector<int> &arr, int n, int x){
    int first=-1;
    int last=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            if(first==-1) first=i;  //changes -1 to the first occuring index
            last=i; //keeps on updating last
        }
    }
    return {first,last};
}


//USING LOWER BOUND AND UPPER BOUND CONCEPT

int lowerBound(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
} 

int upperBound(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

//calling the function of lower bound and upper bound by applying some conditions

pair<int, int> firstLast2(vector<int> &arr, int n, int target){
    int lb=lowerBound(arr,n,target);
    if(lb==n || arr[lb]!=target) return {-1,-1};
    return {lb,upperBound(arr,n,target)-1};
}

//PURE BINARY SEARCH SOLUTION

int binarySearchFirst(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            first=mid;
            high=mid-1; //here we need to eleminate the right search space
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}


int binarySearchLast(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            last=mid;
            low=mid+1; //here we need to eleminate the left search space 
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last;
}

//calling both the functions 

pair<int,int> final(vector<int> &arr, int n, int target){
    int first=binarySearchFirst(arr,n,target);
    if(first==-1) return {-1,-1};
    int last=binarySearchLast(arr,n,target);
    return {first,last};
}

//COUNTING THE OCCURANCES OF A PARTICULAR ELEMENT 

int count(vector<int> &arr, int n, int target){
    pair<int , int> ans=final(arr,n,target);
    if(ans.first==-1) return 0;
    return ans.second-ans.first +1;
}

