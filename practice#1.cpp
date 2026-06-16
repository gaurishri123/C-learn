//Returning the number of unique elements in an array
#include<bits/stdc++.h>
using namespace std;

vector<int> unique(vector<int> &arr, int n){
    map<int,int> mp;
    vector<int> unique1;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second==1){
            unique1.push_back(it.first);
        }
    }
    return unique1;
}

int main(){
    int n;
    cin>>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> ans=unique(arr,n);
    for(int x:ans) cout<<x<<" ";
    return 0;

}
