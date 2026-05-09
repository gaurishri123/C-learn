//Rotate matrix by 90 degree
//BRUTE FORCE SOLUTION
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n){
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0; i<n; i++){  //it is a sqaure matrix
        for(int j=0; j<n; j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    return ans;
}