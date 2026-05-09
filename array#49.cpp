//Count subarray sum equal 
#include<bits/stdc++.h>
using namespace std;

int subarray(int arr[], int n, int k){
    int cnt=0;
    for(int i=0; i<n; i++){
        int sum=0;      //sum resets here after each loop
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum==k){
                cnt++;
            }
        }
    
    }
    return cnt;
}