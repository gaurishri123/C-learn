//Finding second largest number without sorting 
#include <bits/stdc++.h>
using namespace std;
int secondLargest(vector<int> &arr, int n){
    int largest=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int sLargest=-1; //if the array has negative numbers then take INT_MIN
    for(int i=0; i<n; i++){

        // This is a very important line which updates the sLargest
 
        if(arr[i]>sLargest && arr[i]!=largest){
            sLargest=arr[i];
        }
    }
    return sLargest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= secondLargest(arr,n);
    cout<<ans;
    return 0;
}