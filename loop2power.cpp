#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;
    if(n<1){
        cout<<"not a power of 2";
        return 0;
    }

    while(n%2==0){
        n=n/2;
    }
    if (n==1){
        cout<<"number is power of 2";
    }else{
        cout<<"not a power of 2";
    }


    return 0;
}
 