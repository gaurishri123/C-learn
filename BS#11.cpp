//Finding the minimum number of bouquets to make m bouquets
//given an array, whose values correspond to the days the flower bloom
//we have to find the minimum number of days to make m bouquets having k adjecent flowers

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE APPROACH

//Calcution of maximum
int Max(vector<int> &arr, int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

//Calculation of minimum
int Min(vector<int> &arr, int n){
    int mini=INT_MAX;
    for(int i=0; i<n; i++){
        mini=min(mini,arr[i]);
    }
    return mini;
}

bool possible(vector<int> &arr, int days, int m, int k ){
    int n=arr.size();
    int cnt=0; 
    int noOfBouquets=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=days){
            cnt++;
            
        }
        else{
            noOfBouquets+=(cnt/k); //first it devides the count calculated above with k
            cnt=0; //then turns the count to 0
        }
    }
    //calculating the last segment when it does not go else statement
    noOfBouquets+=(cnt/k);
    if(noOfBouquets>=m){
        return true;
    }
    else{
        return false;
    }
}

int final(vector<int> &arr, int n, int m, int k ){
    
    //Edge case
    if((long long)m*k>n) return -1;

    //using above functions
    int mini=Min(arr,n);
    int maxi=Max(arr,n);

    //Brute force loop
    for(int days=mini; days<=maxi; days++){
        if(possible(arr,days,m,k)==true){
            return days;
        }

    }
    return -1;
}

//OPTIMAL SOLUTION USING BINARY SEARCH

int BS(vector<int> &arr, int n, int m, int k){
    //checking for the impossible test case
    if((long long)m*k>n) return -1;
    int low=Min(arr,n);
    int high=Max(arr,n);
    int ans=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(arr,mid,m,k)==true){
            ans=mid;
            high=mid-1; //since we want a minimum value 
        }
        else{
            low=mid+1;
        }
    }
    return low;// or we can return ans

}

 