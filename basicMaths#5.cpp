#include <bits/stdc++.h>
using namespace std;
//printing divisors of n
/*int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<endl;
        }
    }
    return 0;
}*/ 
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<i<<endl;
        }if(n/i != i){
            cout<<n/i<<endl;
        }
    }
    return 0;
}