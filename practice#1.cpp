//FINDING AN ELEMENT IN A ROTATED SORTED ARRAY
#include<bits/stdc++.h>
using namespace std;

int rotatedArray(int arr[], int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && arr[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
    }
}