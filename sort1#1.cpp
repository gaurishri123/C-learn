#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int mini= i;  //assuming minimum number at index i
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[mini]){    //comparing the progressive index with the assumed minimum
                mini=j;   //replacing the assumed with actual minimum

            }
        }

        int temp= arr[mini]; //swaping the minimum number with the first index
        arr[mini]=arr[i];
        arr[i]=temp;
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    selection_sort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}