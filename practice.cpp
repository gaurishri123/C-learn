//Two Sum
//Better Approach
#include<bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int n, int target){
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            return true;
        }
        else{
            mpp[arr[i]]=i;
        }
    }
    return false;
}

int main(){
    vector<int> arr={2,6,5,8,11};
    int n=arr.size();
    int target=14;
    bool ans=twoSum(arr,n,target);
    cout<<ans;
    return 0;
}