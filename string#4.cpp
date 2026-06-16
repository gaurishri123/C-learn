//finding the longest common prefix
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &str){
    if(str.empty()){
        return "";
    }

    sort(str.begin(), str.end());

    string first=str[0];
    string last=str[str.size()-1];

    int minimumLength=min(first.size(), last.size());
    
    string ans="";

    for(int i=0; i<minimumLength; i++){
        if(first[i]!=last[i]){
            break;
            
        }
        ans+=first[i];
    }
    return ans;
}

int main(){
    vector<string> str;
    string input;
    cin>>input;
    str.push_back(input);
    string ans=longestCommonPrefix(str);
    cout<<ans;
    return 0;
}