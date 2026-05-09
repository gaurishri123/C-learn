//rearrange array elememts by sign
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &arr, int n){
    vector<int> ans(n,0);
    int positive_index=0 , negative_index=1;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            ans[positive_index]=arr[i];
            positive_index+=2;
        }
        else{
            ans[negative_index]=arr[i];
            negative_index+=2; 
        }

    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> result= rearrange(arr,n);
    for(int x:result) {
        cout<<x<<" ";
    }
    return 0;
}