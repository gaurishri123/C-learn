//Checking if the two strings are anagram of each other
#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE SOLUTION

bool anagram(string s, string t){
    if(s.length()!=t.length()){
        return false; 
    }
    sort(t.begin(),t.end());
    sort(s.begin(),s.end());

    for(int i=0; i<s.length(); i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}

//OPTIMAL APPROACH

bool anagram2(string s, string t){
    if(s.length()!=t.length()){
        return false;
    }
    int arr[26]={0};

    for(int i=0; i<s.length(); i++){
        arr[s[i]-'A']++;
    }
    for(int i=0; i<t.length(); i++){
        arr[t[i]-'A']--;
    }
    for(int i=0; i<26; i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;

}