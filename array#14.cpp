//finding intersection of sorted array (brute force approach)
#include <bits/stdc++.h>
using namespace std;

vector<int> findingIntersectedArray(vector<int> &A, int n, vector<int> &B, int m){
    vector<int> ans; //declaring another array that stores answer
    int vis[m]= {0};  //declaring array of size m and storing zero at each index
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i]==B[j] && vis[j]==0){
                ans.push_back(A[i]);
                vis[j]=1; //marking the vis array
                break;
            }

            if(B[j]>A[i]){
                break;
            }
        }
    }
    return ans;
}

int main(){
    int n; 
    cin>>n; 
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];   
    }
    int m; 
    cin>>m;
    vector<int> B(m);
    for(int i=0; i<m; i++){
        cin>>B[i];
    }

    vector<int> result=findingIntersectedArray(A,n,B,m);
    for(int x: result){
        cout<<x<<" ";
    }
    return 0;
}