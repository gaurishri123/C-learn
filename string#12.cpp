//Beauty of strings problem
#include<bits/stdc++.h>
using namespace std;

int beautyOfSum(string& s){
    int n=s.length();
    int sum=0;
    
    for(int i=0; i<n; i++){
        unordered_map<char,int> freq;
        for(int j=i; j<n; j++){
            freq[s[j]]++;

            int mini=INT_MIN;
            int maxi=INT_MAX;

            for(auto it:freq){
                mini=min(mini,it.second);
                maxi=max(maxi,it.second);
            }
            sum+=(maxi-mini);
        }
        
    }
    return sum;
}