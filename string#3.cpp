//Finding the largest possible substring of odd numbers
//remove the leading zeroes from the string

#include<bits/stdc++.h>
using namespace std;

string largestOdd(string &s){
    int ind=-1;

    int i;

    //finding the last odd digit
    for(i=s.length()-1; i>=0; i--){
        //the '0' is subtracted to change the char into int
        if((s[i]-'0')%2==1){
            ind=i;
            break;
        }
    }

    //removing the leading zeroes
    i=0;
    while(i<=ind && s[i]=='0'){
        i++;
    }

    return s.substr(i,ind-i+1);
}

int main(){
    string num;
    cin>>num;
    string result=largestOdd(num);
    cout<<result<<endl;
    return 0;
}