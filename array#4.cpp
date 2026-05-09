//checking if the array is sorted 
#include <bits/stdc++.h>
using namespace std;

int sort_check(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        if(arr[i]<arr[i+1]){    /* the n-1 is written because we check
                                 arr[i]<arr[i+1], but when we reach the last elemet,
                                 the array goes out of scope*/
            
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= sort_check(arr,n);
    cout<<ans;
    
    return 0;
}