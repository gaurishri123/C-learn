//REVERSE A WORD
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    vector<string> words;
    string word="";

    for(int i=0; i<s.size(); i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        else if(!word.empty()){
            words.push_back(word);
            word="";
        }
        
    }
    if(!word.empty()){
        words.push_back(word);
    }

    reverse(words.begin(),words.end());

    string result="";
    for(int i=0; i<words.size(); i++){
        result+=words[i];
        if(i<words.size()-1){
            result+=" "; //adding space 
        }
    }
    return result;
}

/*in the first if else statement, 
we used else if(!word.empty()) istead of writing else if(s[i]==" ") to add
 the last word of the string in words vector since there will be no space
  after the last word of string and hence there will be no statement for 
  us to write */