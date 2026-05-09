//largest element in an array
#include <bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &arr, int n){
    int largest= arr[0]; //assuming largest element to be the first element
    for(int i=0; i<n; i++){
        if(arr[i]> largest){
            largest=arr[i];
        }
    }
    return largest;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= largestElement(arr,n);
    cout<<ans;
    
    return 0;
}