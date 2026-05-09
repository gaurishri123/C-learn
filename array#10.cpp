//optimal approach for previous problem
#include <bits/stdc++.h>
using namespace std;

vector<int> zero_end(vector<int> arr, int n){
    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;

        }
        
    }
    //no zeroes
    if(j==-1){
        return arr;
    }

    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> a=zero_end(arr,n);
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}

