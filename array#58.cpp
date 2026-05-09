//Counting the subarrays with xor as k
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE
int subArray(vector<int> &arr, int n, int target){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int XOR=0;
            for(int k=i; k<=j; k++){
                XOR=XOR^arr[k];
            }
            if(XOR==target){
                cnt++;
            }
        }
    }
    return cnt;
}

//BETTER SOLUTION

int subArray2(vector<int> &arr, int n, int target){
    int cnt=0;
    for(int i=0; i<n; i++){
        int XOR=0;
        for(int j=i; j<n; j++){
            XOR=XOR^arr[j];
            if(XOR==target){
                cnt++;
            }
        }
    }
    return cnt;
}

//OPTIMAL SOLUTION
//Revise this as many times as possible

int subArray3(vector<int> &arr, int n, int k){
    int xr=0;
    map<int,int> mpp; //stores prefix xor as key and number of occurances as value
    mpp[xr]++; //{0,1}
    int cnt=0;
    for(int i=0; i<n; i++){
        xr=xr^arr[i];
        //k
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}