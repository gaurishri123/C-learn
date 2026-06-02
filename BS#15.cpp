//Aggresive cows problem
#include<bits/stdc++.h>
using namespace std;


//brute force solution

bool CanWePlace(vector<int> &arr, int dist, int cows){
    int n=arr.size();
    int cnt_cows=1;
    int last=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-last>=dist){
            cnt_cows++;
            last=arr[i];
        }
    }
    if(cnt_cows>=cows){
        return true;
    }
    else{
        return false;
    }
}

int final(vector<int> &arr, int n, int cows){
    int maxi=*max_element(arr.begin(),arr.end());
    int mini=*min_element(arr.begin(),arr.end());
    sort(arr.begin(), arr.end());
    for(int i=1; i<=maxi-mini; i++){ //here i represents the minimum distance not the array index
        if(CanWePlace(arr,i,cows)==true){
            continue;
        }
        else{
            return i-1;
        }
    }
    return maxi-mini;
}

//optimal binary search solution

int binarySearch(vector<int> &arr, int n, int cows){
    sort(arr.begin(),arr.end());
    int low=1;
    int high=arr[n-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(CanWePlace(arr,mid,cows)==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }


    }
    return high;  //opposite polarity
}