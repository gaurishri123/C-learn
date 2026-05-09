//Leaders in an array
//everything to the right of the leader should be smaller
//BRUTE FORCE SOLUTION
#include<bits/stdc++.h>
using namespace std;

vector<int> Leader(int arr[], int n){
    vector<int> ans;
    for(int i=0; i<n;i++){
        int leader=true;
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];

    }
    vector<int> result=Leader(arr,n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;

}