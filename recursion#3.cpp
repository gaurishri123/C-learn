#include <bits/stdc++.h>
using namespace std; //taking from user
int cnt=0;
void print(int n){
    if(cnt==n){
        return;
    }
    cout<<"gauri"<<endl;
    cnt++;
    print(n);
}
int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
}