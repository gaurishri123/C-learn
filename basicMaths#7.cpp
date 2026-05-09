#include <bits/stdc++.h>
using namespace std;
//hcf
int main(){
    int n1;
    int n2;
    cin>>n1>>n2;
    int gcd= 1;
    for(int i=min(n1,n2); i>=1; i--){
        if(n1%i==0 && n2%i==0){
           gcd=i;
           cout<<gcd;
           break;
        }
        
        
    }

    return 0;
}