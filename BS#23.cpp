//Finding the peak element in a 2D matrix 
//None of the adgecent cells of the 2D matrix are similar

//OPTIMAL SOLUTION
#include<bits/stdc++.h>
using namespace std;

//finding the row number of the max element in the column

int findingRow(vector<vector<int>> &matrix, int n, int m, int col){
    int max_row=0;
    for(int i=0; i<n; i++){
        
        if(matrix[i][col]>matrix[max_row][col]){
            max_row=i;
        } 

    }
    return max_row;
}

pair<int,int> findingPeak(vector<vector<int>> &matrix, int n, int m){
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=findingRow(matrix,n,m,mid);
        //Anything beyond the scope of matrix is considered -1
        int left=mid-1>=0 ? matrix[row][mid-1] :-1; //that is left works on columns from L-R and till left>=0
        int right=mid+1<m ? matrix[row][mid+1] :-1; //Similarly right works on columns from R-L till all the rows as completed
        if(matrix[row][mid]>left && matrix[row][mid]>right){
            return {row,mid};
        }
        else if(matrix[row][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return {-1,-1};
}