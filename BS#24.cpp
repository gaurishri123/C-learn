//Finding the median of a row wise sorted matrix
#include<bits/stdc++.h>
using namespace std;

//converting a 2D matrix in a 1D array

int findingMedian(vector<vector<int>> &matrix, int n, int m){
    vector<int> arr;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    //returning the median
    return arr[(n*m)/2];

}