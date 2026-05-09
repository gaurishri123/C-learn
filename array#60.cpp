//Merge two sorted arrays without extra space
#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//TWO POINTER APPROACH

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m){
    int left=0;
    int right=0;
    int index=0;
    long long arr3[n+m];
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            index++, left++;
        }
        else{
            arr3[index]=arr2[right];
            index++,right++;
        }
    }
    //if one of the arrays is exhausted
    //right is exhausted

    while(left<n){
        arr3[index]=arr1[left];
        index++; left++;
    }

    //left is exhausted

    while(right<n){
        arr3[index]=arr2[right];
        index++, right++;
    }

    //putting every element of arr3 back in arr1 and arr2

    for(int i=0; i<n+m; i++){
        if(i<n){
            arr1[i]=arr3[index];
        }
        else{
            arr2[i-n]=arr3[index];
        }
    }

}

//OPTIMAL SOLUTION 1

void merge1(long long arr1[], long long arr2[], int n, int m){
    int left=n-1;
    int right=0;

    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--, right++;
        }
        else{
            break; /* since it is already int the sorted order, after a 
                      certain swap, there will be no conditon of swaping */
        }
    }
    sort(arr1,arr1+n);  //sorting of an arr which is not a vector
    sort(arr2,arr2+n);
}