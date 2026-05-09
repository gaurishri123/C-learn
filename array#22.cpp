//finding number appearing ones while others appear twice in an array
//OPTIMAL SOLUTION
#include<bits/stdc++.h>
using namespace std;

int oneAppearance(int arr[], int n){
    int xor1=0;
    for(int i=0; i<n; i++){
        xor1=xor1^(arr[i]);
    }
    return xor1;

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