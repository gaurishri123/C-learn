//BOOK ALLOCATION QUESTION

//allocate the books to n students so that the maximum number of pages allocated is minimum

//CONDITIONS:-
//A book will be alloted to one student
//Each student must get a minimum of one book
//Allotment should be in continuous order

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int barrier, int k){
    int allocatedStu=1;
    int pages=0;                      //here k is number of students
    for(int i=0; i<n; i++){
        if(arr[i]>barrier) return false;
        if(pages+arr[i]>barrier){
            allocatedStu+=1;
            pages=arr[i]; //new allocation
        }
        else{
            pages+=arr[i];
        }
        
    }
    if(allocatedStu>k){
        return false;
    }
    else{
        return true;
    }
}



int binarySearch(vector<int> &arr, int n, int k){
    if(k>n) return -1; //edge case
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(), arr.end(),0); //gives sum of all the elements in the array
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(arr,n,mid,k)==true){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result; //or we can return low because of opposite polarity
}

