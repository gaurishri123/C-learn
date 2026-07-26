//longest subarray with given sum K (postives)

//Brute force

#include<bits/stdc++.h>
using namespace std;
int longestSubarray(int arr[], int n, int k){
    int len=0;
    
    for(int i=0; i<n; i++){
             int sum=0;
        for(int j=i; j<n; j++){
            
            sum+=arr[j];
            
            if(sum==k){
                len=max(len,j-i+1);
            }
            
            
        }
    }
    return len;
    
}

//Better Solution

int longestSubarray2(vector<int> &arr, int n, long long k){
    map<long long, int> presum;
    long long sum=0;
    int maxLength=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==k){
            maxLength=max(maxLength, i+1);

        }
        long long rem=sum-k;
        if(presum.find(rem)!=presum.end()){
            int len=i-presum[rem];
            maxLength=max(maxLength,len);
        }
        if(presum.find(sum)==presum.end()){
        presum[sum]=i;
        }
    }
    return maxLength;
} 


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= longestSubarray(arr,n, k);
    cout<<ans;
    return 0;
}