//stock buy and sell
#include <bits/stdc++.h>
using namespace std;

int maxprofit(int arr[], int n){
    int mini= arr[0];
    int maxProfit= 0;
    for(int i=0; i<n; i++){
        int cost=arr[i]- mini;
        maxProfit= max(maxProfit, cost);
        mini= min(mini, arr[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    int ans= maxprofit(arr,n);
    cout<<ans;
    return 0;
}