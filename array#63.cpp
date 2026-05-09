//REVERSE PAIR PROBLEM
//CONDITION IS i<j && a[i]>2a[j]

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION

int reversePair(vector<int> &arr, int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>(2*arr[j])){
                cnt++;
            }
        }
    }
    return cnt;
}


//OPTIMAL SOLUTION
//USING THE CONCEPT OF MERGE SORT

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i]>(2*arr[right])){
            //the loop runs till the condition is correct;

            right++;
            
            //By doing right++, the right is now at the first invalid position

        }
     
        cnt+=(right-(mid+1));

        //now for loops proceed and the same process is followed
        //this cnt is outside the loop to prevent overcounting
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt=0;
    //base case
    if(low<=high){
        return cnt;
    }                     /* we are counting again and again since we did 
                            ndt declare a global variable as it is highly 
                            discouraged  */

    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low, mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
