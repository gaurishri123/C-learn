//Searching in a twoD sorted matrix when a target is given 
#include<bits/stdc++.h>
using namespace std;

//Brute force solution
//0(n*m) time complexity

bool search(vector<vector<int>> &matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
}

//BETTER SOLUTION SOLUTION

bool lowerBound(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(arr[ans]==k) return true;
}

bool search2(vector<vector<int>> &matrix, int n, int m, int k){
    for(int i=0; i<n; i++){
        if(matrix[i][0]<=k && matrix[i][m-1]>=k){
            return lowerBound(matrix[i], m, k);
        }
    }
    return false;
}

//OPTIMAL SOLUTION

//In this solution we are working a binary search on a hypothetical 1D array
//This hypothetical 1D array has been generated from 2D matrix
//Here we need to convert the hypothetical 1D index into 2D index
// row=index/m, column=index%m
//TC=0(log(n*m))

bool search3(vector<vector<int>> &matrix, int n, int m, int target){
    int low=0;
    int high=(n*m-1);
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m, column=mid%m;
        if(matrix[row][column]==target){
            return true;
        }
        else if(matrix[row][column]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}