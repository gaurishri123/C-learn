//LOWER BOUND
/*We have been given a target value and we have to look for the 
 smallest index which is greater than or equal to the given target */

 #include<bits/stdc++.h>
 using namespace std;

 int lowerBound(int arr[], int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        //maybe an ans
        if(arr[mid]>=target){
            ans=mid;
            //look for more small index at left
            high=mid-1;

        }
        //look for right
        else{
            low=mid+1;
        }
    }
    return ans;
 }

 //UPPER BOUND
 /*The only difference is that we have to find the smallest index which
    is greater than the given target not equal to */
  
int upperBound(int arr[], int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            mid=ans;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}   

/*The search insert problem in leetcode has the exact same
logic as the lower bound */