//Recursive implementation of atoi() functiom
#include<bits/stdc++.h>
using namespace std;

//calling the helper recursive function
//this function only helps to determine the character into integer and handle the overflow situation

const int INT_MIN_VAL=-2147483648;
const int INT_MAX_VAL=2147483647;

int helper(const string &s, int i, long long num, int sign){
    //base line code
    //if the inidex goes out of bound or the string character is not a digit
    if(i>=s.size() || !isdigit(s[i])){
        return (int)sign*num;
    }

    //building the number
    num=num*10+(s[i]-'0'); //s[i]-'0' is required to change the character of the string to digit 
                            
    //handling overflow conditions
    if(sign*num<INT_MIN_VAL) return INT_MIN_VAL;
    if(sign*num>INT_MAX_VAL) return INT_MAX_VAL;

    return helper(s,i+1,num,sign);
    

}

int atoi(string& s, int i=0){
    //skipping the leading spaces
    while(i<s.size() && s[i]==' '){
        i++;
    }

    //handling the sign

    int sign=1;
    if(i<s.size() && (s[i]=='+' || s[i]=='-')){
        sign=(s[i]=='-')? -1:1;
        i++;
    }

    //calling recursive helper

    return helper(s,i,0,sign);
}

int main(){
    string s;
    cin>>s;
    int ans=atoi(s);
    cout<<ans;
    return 0;
}