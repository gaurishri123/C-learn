//Finding the Kth missing number in a positively increasing array

#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE SOLLUTION

int findMissing(vector<int> &arr, int k){
    int n=arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            k++;
        }  //here k is constantly increasing but according to the logic, if arr[i]>k then answer is till k 
        else{
            break;
        }
    }
    return k;
}

//OPTIMAL BINARY SEARCH SOLUTION

int binarySearch(vector<int> &arr, int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        //how many numbers are missing till the mid value
        //ex:[2,3,4,7,11] mid is pointing at 4
        //ideally at the place of 4, 3 should be there so if we do 4-3 we get the number of missing numbers
        //4 is at 2nd index and if we do missing formula, answer will be 1
        // this indicates that there is only one missing number till 4 which is 1

        int missing= arr[mid]-(mid+1);

        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    //due to opposite polarity 
    return high+1+k;         
                     // the ans will be arr[high]+more;
                     //this more can be calculated is k-missing
                     //and for high, the missing will be arr[high]-(high+1)
                     //the whole formula then becomes arr[high]+k-(arr[high]-high-1)
                     //== arr[high]+k-arr[high]+high+1
                     //hence the total ans is high+k+1;

}