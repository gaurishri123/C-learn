//SEARCH ELEMENT IN A ROTATED SORTED ARRAY WITHOUT DUPLICATES 
#include<bits/stdc++.h>
using namespace std;

int elementSearch(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        //checking if left side is sorted 
        if(arr[low]<=arr[mid]){

            //checking if target lies on the left side
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }

        

            //else going to the right side
            else{
                low=mid+1;
            }
        }

        // right side is sorted
        else{

            //if target lies on the right side
            if(target>=arr[mid] && target<=arr[high]){
                low=mid+1;
            }

            //else searching on the left side
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

//SEARCH ELEMENTS IN A ROTATED SORTED ARRAY WITH DUPLICATES
//EDGE CASE A={3 1 2 3 3 3} here since the a[low]==a[mid]==a[high] we can't compare

int elementSearch(vector<int> &arr, int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return true;
        }
        //edge case
            if(arr[low]==arr[mid] && arr[mid]==arr[low]){
                low++;
                high--;
                continue; /*we use continue here so as to go again through
                          the entire code  and check for more edge cases
                          without following if else */
            }


        //checking if left side is sorted 
        if(arr[low]<=arr[mid]){

            //checking if target lies on the left side
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }

            //else going to the right side
            else{
                low=mid+1;
            }
        }

        // right side is sorted
        else{

            //if target lies on the right side
            if(target>=arr[mid] && target<=arr[high]){
                low=mid+1;
            }

            //else searching on the left side
            else{
                high=mid-1;
            }
        }
    }
    return false;
}
