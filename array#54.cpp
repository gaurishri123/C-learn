//Majority element II
//element occuring more than n/3
//Brute force
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElemet(vector<int> &arr, int n){
    vector<int> list;
    for(int i=0; i<n; i++){
        if(list.size()==0 || list[0]!=arr[i]){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(arr[j]==arr[i]){
                    cnt++;
                    if(cnt>n/3){
                        list.push_back(arr[i]);
                    }
                }
                
            }
            if(list.size()==2){  //at max, list can have only 2 elements
                break;
            }
        }
    }
    return list;
}

//BETTER SOLUTION
//HASHING
vector<int> majorityElement2(vector<int> &arr,int n){
    vector<int> list;
    map<int,int> mpp;
    int min=(n/3)+1;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==min){
            list.push_back(arr[i]);
        }
        if(list.size()==2){
            break;
        }
    }
    sort(list.begin(),list.end());
    return list;
}

//OPTIMAL SOLUTION
//SAME CANCELLATION INTUTION AS N/2 PROBLEM
vector<int> majorityElement3(vector<int> &arr, int n){
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0; i<n; i++){
        if(cnt1==0 && el2!=arr[i]){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && el1!=arr[i]){
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1){
            cnt1++;
        }
        else if(arr[i]==el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1=0;
    cnt2=0;
    int min=(n/3)+1;
    for(int i=0; i<n; i++){
        if(arr[i]==el1){
            cnt1++;
        }
        if(arr[i]==el2){
            cnt2++;
        }
        
    }
    if(cnt1>=min){
        ls.push_back(el1);
    }
    if(cnt2>=min){
        ls.push_back(el2);
    }
    return ls;

    
}