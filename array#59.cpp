//MERGE OVERLAPPING INTERVALS

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION

vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    
    for(int i=0; i<n; i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

//OPTIMAL SOLUTION

vector<vector<int>> mergeOverlapping2(vector<vector<int>> &arr, int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        //adding of new {a,b}
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        //extending the array interval
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}