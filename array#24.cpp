//two sum BRUTE FORCE
#include <bits/stdc++.h>
using namespace std;

string two_sum(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                return "yes";
            }
        }                              /* if we want to return indexes, specify
                                        the return type to be vector and array to 
                                        be vector*/
    }
    return "no";
    
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<two_sum(arr,n,target);
    return 0;
}