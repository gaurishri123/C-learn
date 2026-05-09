//two sum BETTER SOLUTION
#include <bits/stdc++.h>
using namespace std;

string two_sum(vector<int> &arr, int n, int target){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        int a= arr[i];
        int more= target-a;
        if(mpp.find(more)!=mpp.end()){     //hashing used in this questiom
            return "yes";                 //stores element array as key
        }                                  //index as value   
        mpp[a]=i;    
    }
    return "no";
    

}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<two_sum(arr,n,target);
    
    return 0;
}