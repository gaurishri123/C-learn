//Leader of an array
//OPTIMAL SOLUTION
#include<bits/stdc++.h>
using namespace std;

vector<int> Leader(vector<int> &arr, int n){
    int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        //keeping track of highest number from right
        maxi=max(maxi,arr[i]);
    }
    //giving the sorted answer
    sort(ans.begin(),ans.end());    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> result=Leader(arr,n);
    for(int i=0; i<result.size() ;i++){
        cout<<result[i]<<" ";
    }
    return 0;
    
}