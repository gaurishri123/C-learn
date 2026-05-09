//majority sum BETTER SOLUTION
#include<bits/stdc++.h>
using namespace std;

int majority_sum(int arr[], int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
        return maxi;

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