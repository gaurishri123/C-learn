//linear Search
#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int d){
    for(int i=0; i<n; i++){
        if(d==arr[i]){
            return i;
        }
        return -1;
    }
}

int main(){
    int n; 
    cin>>n;
    int d; 
    cin>>d; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<linear_search(arr,n,d);
    return 0;
}