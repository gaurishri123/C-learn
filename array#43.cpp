//set matrix zeroes
//Brute force approach

#include<bits/stdc++.h>
using namespace std;

void mark_row(vector<vector<int>> &matrix, int m, int i){
    for(int j=0; j<m; j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}

void mark_column(vector<vector<int>> &matrix, int n, int j){
    for(int i=0; i<n; i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}

void final_matrix(vector<vector<int>> &final, int n, int m){
    for( int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(final[i][j]==0){
                mark_row(final,n,i);
                mark_column(final,m,j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(final[i][j]==-1){
                final[i][j]=0;
            }
        }
    }
}

