//Finding out the smallest devisor which gives the sum of individual divisions to be lesser than equal to the threshold value
#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int d){
    int n=arr.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=ceil((double) arr[i]/(double) d);
    }
    return sum;
}

int smallestDevisor(vector<int> &arr, int threshold){
    int n=arr.size();
    if(n>threshold) return -1;
    int low=1;
    int high=*max_element(arr.begin(),arr.end());
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        if(sumByD(arr,mid)<=threshold){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low; //or we can return ans as well
}