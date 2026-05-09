//Optimal approach of 49
#include<bits/stdc++.h>
using namespace std; 
//did not understand it at all!!

int subarray(vector<int> &arr, int n, int k){
    map<int, int> mpp;
    mpp[0]=1;
    int presum=0,cnt=0;
    for(int i=0; i<n; i++){
        presum+=arr[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;

    }
    return cnt;
}