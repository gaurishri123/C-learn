//majority element OPTIMAL SOLUTION
// moore's voting algorithm
#include <bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &arr, int n){
    int cnt=0;
    int el=NULL;
    for(int i=0; i<n; i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    int cnt1=0;
    for(int i=0; i<n; i++){
        if(arr[i]==el){
            cnt1++;
        }
    }
    if(cnt1> n/2){
        return el;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    int ans= majority_element(arr,n);
    cout<<ans;
    return 0;
}