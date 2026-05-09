//finding the number that appears ones while others appear twice in array
//BETTER SOLUTION
#include<bits/stdc++.h>
using namespace std;
int oneAppearance(int arr[], int n){
     map<int ,int > mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;  //key as element and count as the number 
    }
    for(auto it:mpp){
        if(it.second==1){
            return it.first;
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
    int result= oneAppearance(arr, n);
    cout<<result;
    return 0;
}