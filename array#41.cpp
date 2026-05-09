//Longest consecutive sequence 
//BETTER SOLUTION
#include<bits/stdc++.h>
using namespace std;

int longestSequence(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    int lastSmallest=INT_MIN;
    int longest=1;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]-1==lastSmallest){
            cnt+=1;
            lastSmallest=arr[i];
        }
        else if(lastSmallest!=arr[i]){
            cnt=1;
            lastSmallest=arr[i];
            
        }
        longest=max(longest,cnt);
    }
    return longest;
    

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans=longestSequence(arr,n);
    cout<<ans;
    return 0;
}