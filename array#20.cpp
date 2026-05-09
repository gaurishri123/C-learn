//finding the number that appears ones and other numbers twice(brute force)
//Time Complexity=0(n^2) since nested loop

#include<bits/stdc++.h>
using namespace std;

int oneAppearance(int arr[], int n){
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[j]==arr[i]){
                cnt++;
            }
        }
        if(cnt==1){
            return arr[i];
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
    int result= oneAppearance(arr,n);
    cout<<result;
    return 0;
}