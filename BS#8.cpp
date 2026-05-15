//FINDING THE FLOOR OF SQAURE ROOT OF NUMBER 

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION(BIG0(N))

int floorSqrt(int n){
    int ans=1;
    for(int i=0; i<=n; i++){
        if((i*i)<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

//OPTIMAL SOLUTION

int floorSqrt(int n){
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        long long mid=(low+high)/2;
        long long val=mid*mid;
        if(val<=n){
            ans=(int)mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans; //we can also return high as high will eventually point to the desired answer
}