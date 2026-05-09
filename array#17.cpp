//finding the missing numbers (brute force)
#include <bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n){
    for(int i=1; i<=n; i++){
        int flag=0;
        for(int j=0; j<n-1; j++){
            if(arr[j]==i){
                flag=1; //means that the number exists
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    int result = missingNumber(arr,n);
    cout<<result;
    return 0;

}