//Finding the row with maximum one's
//Given matrix rows are sorted

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLLUTION
//We go to every row and check each column

int maxOne(vector<vector<int>> &matrix){
    int n=matrix.size(); //rows
    int m=matrix[0].size(); //columns
    int index=-1;
    int maxCnt=-1;
    for(int i=0; i<n; i++){
        int cntRows=0;
        for(int j=0; j<m; j++){
            cntRows+=matrix[i][j];
        }
        /*we are not using here "=" since if any 
        two rows have samw number of ones we want the least row nummber
        */
        if(cntRows>maxCnt){
            maxCnt=cntRows;
            index=i;
        }
    }
    return index;
}

//OPTIMAL SOLUTION
//We treat every row of the matrix as an individual array whose size will be equal to number of columns

int lowerBound(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans =n;
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
    return ans;
}

int maxOne2(vector<vector<int>> &matrix, int n, int m){
    int maxCnt=0;
    int index=-1;
    for(int i=0; i<n; i++){
        int cntOne=m-lowerBound(matrix[i],m,1);
        if(cntOne>maxCnt){
            maxCnt=cntOne;
            index=i;
        }
    }
    return index;
}

/* we have initialised maxCnt to be 0 and index to be -1
as the question stated if there is no row with atleast one 1, 
return -1 as the ans. therefore in that case the maxCnt will not 
get updated and we will get the ans as -1*/