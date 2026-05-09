//COUNT INVERSIONS IN AN ARRAY
//Return the count of pairs which are forming in the array where left element is larger than the right element
//We can only traverse unidirectionally in the array i.e from L to R

#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION

int countInversion(vector<int> &arr, int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                cnt++;
            }
        }
    }
    return cnt;
}

//OPTIMAL SOLUTION
//See the merge sort video and this video then try out the problem 