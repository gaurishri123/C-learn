//NEXT PERMUTATION
//optimal solution
//for better solution c++ offers STL data structure

#include<bits/stdc++.h>
using namespace std;


//take for example arr[]={2,1,5,4,3,0,0}
//the array is increasing from right to left till the dip at 1


vector<int> nextPermutation(vector<int> &arr, int n){
    int index=-1;
    for(int i=n-2; i>=0; i--){

        //sudden dip from right at 5 and 1

        if(arr[i]<arr[i+1]){
            index=arr[i];
            break;
        }
    }

    //if there is no dip

    if(index==-1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    //finding any element in the array which is greater than 1 but close enough
    //then swaping them

    for(int i=n-1; i>index; i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    //after this the array becomes {2 3 5 4 1 0 0}
    //since it is in increasing order till the swap we did
    //hence we will reverse the array from right to left till the swap

    reverse(arr.begin()+index+1, arr.end());

    //returning the final array without using any extra space
    //means making changes in the original array

    return arr;


}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> result= nextPermutation(arr,n);
    for(int x:result) {
        cout<<x<<" ";
    }
    return 0;
}