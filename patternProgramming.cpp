//Pattern Programming
#include<bits/stdc++.h>
using namespace std;

//i here signifies how many rows
//j signifies how many numbers are going to be in that row

void pattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=1; i<=n; i++){
        for(int j=n; j>=i; j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=1; i<=n; i++){
        int a=1;
        for(int j=n; j>=i; j--){
            cout<<a;
            a++;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=(2*i-1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=(2*i-1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
} 

void pattern13(int n){
    int a=1;
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=i; j++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n; 
    pattern(n);
    cout<<endl;
    pattern2(n);
    cout<<endl;
    pattern3(n);
    cout<<endl;
    pattern4(n);
    cout<<endl;
    pattern5(n);
    cout<<endl;
    pattern6(n);
    cout<<endl;
    pattern7(n);
    cout<<endl;
    pattern8(n);
    cout<<endl;
    pattern13(n);
    return 0;
}

