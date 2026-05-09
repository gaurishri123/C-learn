#include <iostream>
using namespace std;
//checking the palindrome
int main(){
    int n;
    cin>>n;
    int dup=n;
    int revN=0;
    while(n>0){
    int lastDigit=n%10;
    revN= (revN*10)+lastDigit;
    n=n/10;
    }if(dup==revN){
        cout<<"true";
    }else{
        cout<<"false";
    }

    return 0;
}