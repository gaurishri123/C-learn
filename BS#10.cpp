//KOKO EATING BANANAS PROBLEM
//Return the minimum integer k so that koko can eat all the bananas within h hours

#include<bits/stdc++.h>
using namespace std;

int requiredTime(vector<int> &arr, int hour){
    int n=arr.size();
    int totalTime=0;
    for(int i=0; i<n; i++){
        totalTime+=ceil(arr[i]/hour);
    }
    return totalTime;
}

int kokoBanana(vector<int> &arr, int hours){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int totalHours=requiredTime(arr,mid);
        if(totalHours<=hours){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}