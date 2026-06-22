//finding the maximum depth of parenthesis in a string
#include<bits/stdc++.h>
using namespace std;

int maxDepth(string &s){
    int p=0;
    int ans=0;
    for(char ch:s){
        if(ch=='(') p++;
        else if(ch==')') p--;
        ans=max(ans,p);
    }
    return ans;

}

int main(){
    string s;
    cin>>s;
    int result=maxDepth(s);
    cout<<result;
    return 0;
}