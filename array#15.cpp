#include <bits/stdc++.h>
using namespace std;

vector<int> findingIntersectedArray(vector<int> &A, int n, vector<int> &B, int m){
   vector<int> ans;
   int i=0; 
   int j=0;
   while(i<n && j<m){
    if(A[i]<B[j]){
        i++;
    }
    if(B[j]<A[i]){
        j++;
    }
    else{
        ans.push_back(A[i]);
        i++;
        j++;
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