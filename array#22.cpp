//Finding The longest subarray with sum as k (positives as well as negatives)
#include<bits/stdc++.h>
using namespace std;
//Optimal solution

int longestSubarray(vector<int> &arr, int n,long long k){
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

