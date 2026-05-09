//To compute the length subarray whose sum equals zero
//containing both negative and positive integers 
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE 
int largestSubarray(vector<int> &arr, int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        int sum=0;;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum==0){
                int length=j-i+1;
                maxi=max(maxi,length);
                
            }
        }
        
    }
    return maxi;
}

//OPTIMAL SOLUTION

int largestSubarray(int arr[], int n){
    unordered_map<int,int> mpp;
    int sum=0;
    int maxi=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]); //if prefix sum is found in the hashmap
            }
            else{
                mpp[sum]=i; /* if prefix sum is not found in the 
                               hashmap then it is stored in hashmap
                               as key and index as it's value */
            }
        }
    }
    return maxi;    
}

