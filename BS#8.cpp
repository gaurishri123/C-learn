//FINDING THE FLOOR OF SQAURE ROOT OF NUMBER 

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION(BIG0(N))

int floorSqrt(int n){
    for(int i=0; i<=n; i++){
        if((i*i)<=n){
            return i;
        }
        else{
            break;
        }
    }
}

//OPTIMAL SOLUTION

int floorSqrt(int n){
    int low=1;
    int high=n
}