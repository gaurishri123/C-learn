//Rearranging the elements of an array in alternate positive and neagtive order
#include<bits/stdc++.h>
using namespace std;

vector<int> alternation(vector<int> &arr, int n){
    vector<int> positive;
    vector<int> negative;
    for(int i=0; i<n; i++){
        if(arr[i]>=0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i=0; i<n; i++){
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }
    return arr;
}