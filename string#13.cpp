#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    vector<string> words;
    for(int i=0; i<s.length(); i++){
        string word="";
        for(int j=i; j<s.length(); j++){
            word+=s[j];
            words.push_back(word);
        }
    }

    int min_vaL=INT_MAX;
    int max_val=INT_MIN;

    string ans="";
    for(int i=0; i<words.size(); i++){
        string reversed_word=words[i];
        reverse(reversed_word.begin(), reversed_word.end());
        if(words[i]==reversed_word && words[i].length()>ans.length()){
            ans=words[i];
        }
    }
    return ans;

}