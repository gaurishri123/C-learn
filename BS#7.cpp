//FINDING THE PEAK ELEMENT FROM AN ARRAY
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//Assuming -infinity on both the sides of array

vector<int> peakElement(vector<int> &arr, int n){
    vector<int> peaks;
    for(int i=0; i<n; i++){
        if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])){
            peaks.push_back(i);
        }
    }
    return peaks;  //there can be multiple peaks so we return a vector 
                   //having all the peaks
}

//OPTIMAL SOLUTION

int peakElement2(vector<int> &arr, int n){
    if(n==1) return 0; //if array has only one element 
    if(arr[0]>arr[1]) return 0; //since left side is always -infinity
    if(arr[n-1>arr[n-2]]) return n-1; //right side is always -infinity
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid-1]<arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
