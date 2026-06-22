//Converting roman numbers to integers
#include<bits/stdc++.h>
using namespace std;

int romanToInteger(string &s){
    int res=0;
    unordered_map<char,int> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for(int i=0; i<s.size()-1; i++){
        if(roman[s[i]]<roman[s[i+1]]){
            res-=roman[s[i]];
        }
        else{
            res+=roman[s[i]];
        }
    }
    return res+roman[s.back()];


}

int main(){
    string s;
    cin>>s;
    int ans=romanToInteger(s);
    cout<<ans;
    return 0;
}