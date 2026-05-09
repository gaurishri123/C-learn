#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;   //taking size of array
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; //putting inputs in the array
    }
    //precomputation
    int hash[13]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]+=1;
     
    }
    int q;
    cin>>q;   //number of queries
    while(q--){
        int number;
        cin>>number; //taking the queries
        //fetch
        cout<<hash[number]<<endl;
    
    }
    return 0;

}