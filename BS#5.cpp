//MINIMUM ELEMENT IN A ROTATED SORTED ARRAY WITHOUT DUPLICATES
#include<bits/stdc++.h>
using namespace std;

int minimumElement(vector<int> &arr, int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){   //if the search space is sorted 
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]); //finding the min element in sorted part
            low=mid+1; //eleminating left half since we have found the minimum element in this part  
        }
        else{
            ans=min(ans,arr[mid]); //we are on the right part i.e if arr[low]>arr[mid]
            high=mid-1;//eleminating right part since we have found the smallest element in this part
        
        }
    }
    return ans;
}

//HOW MANY TIMES AN ARRAY HAS BEEN ROTATED

int arrayRotation(vector<int> &arr, int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){ 
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            } 
            low=mid+1; //eleminating left half
        }
        else{
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            high=mid-1;
        
        }
    }
    return ans;
}