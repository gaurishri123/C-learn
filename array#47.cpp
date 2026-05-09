//Rotate matrix by 90 degree
//OPTIMAL SOLUTION
//Transpose+reverse each row
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reverseMatrix(vector<vector<int>> &matrix, int n){
    //transposing the matrix
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){   //diagonal elements are constant 
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse each array
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}