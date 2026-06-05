//Finding the median of two sorted array
#include<bits/stdc++.h>
using namespace std;

//Brute Force Solution

vector<int> mergeSort(vector<int> &a, vector<int> &b){
    int n1=a.size();
    int n2=b.size();
    vector<int> result;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            result.push_back(a[i]);
            i++;
        }
        else{
            result.push_back(b[j]);
            j++;
        }
    }
    //if b is exhausted
    while(i<n1){
        result.push_back(a[i]);
        i++;
    }
    //if a is exhausted
    while(j<n2){
        result.push_back(b[j]);
        j++;
    }
    return result;
}

double median(vector<int> &a, vector<int> &b){
    vector<int> result= mergeSort(a,b);
    int n=result.size();
    double median=-1.0;
    if(n%2==0){
        int mid1=(n/2)-1;
        int mid2=(n/2);
        median=(result[mid1]+result[mid2])/2;
    }
    else{
        int mid=n/2;
        median=result[mid];
    }
    return median;

}

//OPTIMAL SOLUTION


double medianOfSortedArray(vector<int> nums1, vector<int> nums2){
    if(nums2.size()<nums1.size()) return medianOfSortedArray(nums2,nums1);
    int n1=nums1.size();
    int n2=nums2.size();
    int low=0;
    int high=n1;
    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=(n1+n2+1)/2-cut1; //works for both odd and even 

        int left1=cut1==0? INT_MIN: nums1[cut1-1]; //edge cases
        int left2=cut2==0? INT_MIN: nums2[cut2-1];

        int right1=cut1==n1? INT_MAX: nums1[cut1]; //edge cases
        int right2=cut2==n2? INT_MAX: nums2[cut2];

        if(left1<=right2 && left2<=right1){
            //condition for if the merged array is even
            if((n1+n2)%2==0){
                return(max(left1,left2)+min(right1,right2))/2.0;
            }
            //if the merged array is odd
            else{
                return max(left1,left2);
            }
        }
        else if(left1>right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }
    return 0.0;
}