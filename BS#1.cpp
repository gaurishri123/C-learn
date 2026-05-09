//BINARY SEARCH OF AN ELEMENT IN AN ARRAY GIVEN THE TARGET ELEMENT

//Always remember that binary search questions have a sorted array every time

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

//RECURSIVE CODE

int binarySearch2(vector<int> &arr, int low, int high, int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) return binarySearch2(arr,low, mid-1, target);
    else return binarySearch2(arr,mid+1,high,target);
}

//above is the recursive code and when the compiler tells to write the function:-

int search(vector<int> &arr, int target){
    return binarySearch2(arr,0,arr.size()-1,target);
}