//adding all the zeroes to the end BRUTE FORCE SOLUTION
#include <bits/stdc++.h>
using namespace std;

void zero_end(int arr[], int n){
    vector<int> temp;

    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);  //storing the non-zero elements in temp
        }
    }

    for(int i=0; i<temp.size(); i++){
        arr[i]=temp[i];  //placing the temp vector at front 
    }

    for(int i=temp.size(); i<n; i++){
        arr[i]=0; //placing zero at the remaining places
    }
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    zero_end(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}