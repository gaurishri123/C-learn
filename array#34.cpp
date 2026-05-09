//maximum subarray sum
//kadane's algorithm
#include <bits/stdc++.h>
using namespace std;

long long subarray(int arr[], int n){
    long long sum=0;
    long long maxi= LONG_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
        }

        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int result= subarray(arr,n);
    cout<<result;
    return 0;
}