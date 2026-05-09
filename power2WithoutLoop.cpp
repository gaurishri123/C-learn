#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;

    if(n>0 && (n & (n-1))==0){
        cout<<"number is power of 2";
    }else{
        cout<<"number is not power of 2";
    }

    return 0;
}