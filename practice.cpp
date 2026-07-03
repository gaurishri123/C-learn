//finding the Majority element 
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr, int n){
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second>n/2){
            return it.first;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans=majorityElement(arr,n);
    cout<<ans;
    return 0;
}