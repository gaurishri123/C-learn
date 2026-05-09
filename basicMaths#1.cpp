#include<iostream>
using namespace std; //counting the number of digits

int main(){
    int n;
    cin>>n;
    int cnt=0;
    while(n>0){
        int lastDigit=n%10;
        cnt=cnt+1;
        n=n/10;
        //cout<<lastDigit<<endl;
    }
    cout<<cnt;
    return 0;
}
//counting the number of digits