#include<bits/stdc++.h>
using namespace std;

int daysRequired(vector<int> &weight, int capacity){
    int days=1;
    int load=0;
    int n=weight.size();
    for(int i=0; i<n; i++){
        if(load+weight[i]>capacity){
            days=days+1;
            load=weight[i];
        }
        else{
            load+=weight[i];
        }
    }
    return days;

}

int sum(vector<int> weight, int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=weight[i];
    }
    return sum;
}

int binarySearch(vector<int> &weight, int days){
    int n=weight.size();
    int low=*max_element(weight.begin(), weight.end());
    int high=sum(weight, n);
    while(low<=high){
        int mid=(low+high)/2;
        if(daysRequired(weight,mid)<=days){
            high=mid-1;
        }          
        else{
            low=mid+1;
        }
    }
    return low;  //we don't actually require the answer variable
}              // the binary search will automatically point to the low after it's completion