//majority element BETTER SOLUTION
//hashing
#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &arr, int n){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second> n/2){
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
    int ans= majority_element(arr,n);
    cout<<ans;
    return 0;
}