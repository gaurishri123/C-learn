//Painter's Problem or Split array to have maximum sum which is minimum
//Similar to the previous problem that is book allocation
#include<bits/stdc++.h>
using namespace std;

bool allocationIsPossible(vector<int> &arr, int n, int barrier, int k){
    long long unitToPaint=0;
    int painter=1;
    for(int i=0; i<n; i++){
        if(arr[i]>barrier) return false;
        if(arr[i]+unitToPaint>barrier){
            painter+=1;
            unitToPaint=arr[i];

        }
        else{
            unitToPaint+=arr[i];
        }
    }
    if(painter>k){
        return false;
    }
    else{
        return true;
    }
}

int binarySearch(vector<int> &arr, int n, int k){
    //edge case
    if(k>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(allocationIsPossible(arr,n,mid,k)==true){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;  //or we can return low as well

    
}

int splitArray(vector<int>& nums, int k) {
        
    }