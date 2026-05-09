//majority sum subarray BRUTE FORCE
#include<bits/stdc++.h>
using namespace std;

int majority_sum(int arr[], int n){
    int maxi= INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+=arr[k];
                maxi=max(sum,maxi);
                
            }
            return maxi;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    int ans= majority_sum(arr,n);
    cout<<ans;
    return 0;
}