//FINDING SINGLE ELEMENT IN AN ARRAY
//REST OF THE ELEMENTS APPEAR TWICE
//ONLY ONE ELEMENT APPEAR ONCE 

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//In this solution we have to write conditions for first and last element separately
//Otherwise the array will go out of scope and a runtime error comes

int singleElement(vector<int> &arr, int n){
    if(n==1) return arr[0];

    for(int i=0; i<n; i++){
        if(i==0){
            if(arr[i]!=arr[i+1]) return arr[i];
        }
        else if(i==n-1){
            if(arr[i]!=arr[i-1]) return arr[i];
        }
        else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]) return arr[i];
        }
    }
    return -1;
}

//OPTIMAL SOLUTION

//(EVEN,ODD)-> ELEMENT IS ON RIGHT HALF, ELEMINATE LEFT HALF
//IF EVEN==ODD, WE ARE ON THE LEFT HALF AND ELEMENT IS ON THE RIGHT

//(ODD,EVEN)-> ELEMENT IS ON THE LEFT HALF, ELIMINATE THE RIGH HALF
//IF ODD==EVEN, WE ARE ON THE RIGHT HALF AND ELEMENT IS ON THE LEFT

//EVEN AND ODD ARE INDEX POSITIONS NOT THE ELEMENT

int singleElement2(vector<int> &arr, int n){
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid] !=arr[mid-1]) return arr[mid];

        //left half
        if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])){
            low=mid+1; //elemination of left
        }
        else{
            high=mid-1; //else right half, elemination of right
        }
    }
    return -1;
}