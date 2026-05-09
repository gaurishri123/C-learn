//sorting an array of zeroes and ones BETTER SOLUTION
#include <bits/stdc++.h>
using namespace std;

void sort_arr(vector<int> &arr, int n){
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }else{
            cnt2++;
        }
        
    }

    for(int i=0; i<cnt0; i++){
        arr[i]=0;    /*single "=" is used to assign and dounble "= =" are used
                         to check a condition for example true or false*/
    }
    for(int i=cnt0; i<cnt0+cnt1; i++){
        arr[i]=1;
    }
    for(int i=cnt0+cnt1; i<n; i++){
        arr[i]=2;
    }

    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort_arr(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

/* the brute force soution is to use merge sort 
having time complexity of nlogn */
