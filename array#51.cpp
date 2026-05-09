//Pascal's Triangle
//returning the elements when row and column numbers are given
#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    long long res=1; //the general formula of finding any element is nCr or (r-1)C(c-1)
    for(int i=0; i<r; i++){
        res=res*(n-i);
        res=res/(i+1);

    }
    return res;
}