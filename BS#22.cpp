//Finding a target in a two D matrix
//The matrix is sorted from left to right as well as from top to bottom
#include<bits/stdc++.h>
using namespace std;

//Brute Force Solution

pair<int,int> findingTarget(vector<vector<int>> &matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

//Better Solution
//Considering each row individually and then doing a binary search on each one of them

int binarySearch(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1; //not found
}

pair<int,int> findingTarget2(vector<vector<int>> &matrix, int n, int m, int target){
    for(int i=0; i<n; i++){
        int col=binarySearch(matrix[i],m,target);
        if(col!=-1){
            return {i,col};
        }
    }
    return {-1,-1};
}

//OPTIMAL SOLUTION
//TC=0(n+m)

pair<int,int> findingTarget3(vector<vector<int>> &matrix, int n, int m, int target){
    int row=0;
    int col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target){
            return {row,col};
        }
        else if(matrix[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    return {-1,-1};
}